#include "HealthPotion.h"
#include "Player.h"
#include <iostream>

HealthPotion::HealthPotion(int amount) : Item("Health Potion", ItemType::HEALTH_POTION), healAmount(amount) {}

void HealthPotion::use(Player& player) {
	player.heal(healAmount);
	std::cout << "You used a Health Potion and recovered " << healAmount << " HP!\n";
}