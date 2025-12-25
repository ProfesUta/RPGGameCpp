#include "Player.h"
#include "HealthPotion.h"
#include <iostream>

Player::Player(const std::string& name) : name(name), level(1), xp(0), xpToNext(100), maxHp(100), hp(100), attackPower(12) {}

// Getters

std::string Player::getName() const { return name; }
int Player::getHp() const { return hp; }
int Player::getMaxHp() const { return maxHp; }
int Player::getLevel() const { return level; }
int Player::getXp() const { return xp; }
int Player::getXpToNext() const { return xpToNext; }


// Gameplay


int Player::attack() {

	return attackPower;
}

void Player::takeDamage(int dmg) {

	hp -= dmg;
	if (hp < 0) {
		hp = 0;
	}
}

void Player::heal(int amount) {

	hp += amount;
	if (hp > maxHp) {
		hp = maxHp;
	}
}

void Player::gainXp(int amount) {

	xp += amount;
	if (xp >= xpToNext) {
		levelUp();
	}
}

void Player::levelUp() {

	level++;
	xp = 0;
	xpToNext += 50;
	maxHp += 20;
	attackPower += 5;
	hp = maxHp;
	
	std::cout << "\n*** LEVEL UP! You are now level " << level << "! ***\n";
}


// Inventory


void Player::addItem(std::unique_ptr<Item> item) {

	inventory.push_back(std::move(item));
}

void Player::useItem(int index) {

	if (index < 0 || index >= inventory.size())
	{
		std::cout << "Invalid item!\n";
		return;
	}

	inventory[index]->use(*this);
	inventory.erase(inventory.begin() + index);
}

void Player::showInventory() const {

	if (inventory.empty())
	{
		std::cout << "Inventory is empty.\n";
		return;
	}

	for (size_t i = 0; i < inventory.size(); ++i)
	{
		std::cout << i + 1 << ". " << inventory[i]->getName() << "\n";
	}
}

int Player::getInventorySize() const { return inventory.size(); }