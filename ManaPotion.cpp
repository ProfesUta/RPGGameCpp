#include "ManaPotion.h"
#include <iostream>

ManaPotion::ManaPotion(int amount) : Item("Mana Potion", ItemType::MANA_POTION), manaAmount(amount) {}

void ManaPotion::use(Player&) {
    std::cout << "You used a Mana Potion!\n";
}