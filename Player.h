#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class Player
{
private:
	std::string name;
	int level;
	int xp;
	int xpToNext;
	int maxHp;
	int hp;
	int attackPower;
	std::vector<std::shared_ptr<Item>> inventory;

public:
	Player(const std::string& name);

	// Getters

	std::string getName() const;
	int getHp() const;
	int getMaxHp() const;
	int getLevel() const;
	int getXp() const;
	int getXpToNext() const;
	int getInventorySize() const;

	// Gameplay

	int attack();
	void takeDamage(int dmg);
	void heal(int amount);
	void gainXp(int amount);
	void levelUp();

	// Inventory

	void addItem(std::unique_ptr<Item> item);
	void useItem(int index);
	void showInventory() const;

};