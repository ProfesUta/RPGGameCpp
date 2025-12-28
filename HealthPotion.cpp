#include "HealthPotion.h"
#include "Player.h"
#include <iostream>

HealthPotion::HealthPotion() : Item("Health Potion", ItemID::HEALTH_POTION) {}

void HealthPotion::use(Player& player) {

	player.heal(30);
	std::cout << "Your used HP Potion!\n";
}