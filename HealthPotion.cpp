#include "HealthPotion.h"
#include "Player.h"
#include <iostream>

HealthPotion::HealthPotion(int heal) : Item("Health Potion"), healAmount(heal) {}

void HealthPotion::use(Player& player) {
	player.heal(healAmount);
	std::cout << "You used a Health Potion and recovered " << healAmount << " HP!\n";
}