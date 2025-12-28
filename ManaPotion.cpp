#include "ManaPotion.h"
#include "Player.h"
#include <iostream>

ManaPotion::ManaPotion() : Item("Mana Potion", ItemID::MANA_POTION) {}

void ManaPotion::use(Player&) {
    std::cout << "You used a Mana Potion!\n";
    // jer ar maqvs mana damatebuli, es prosta potionia raa :D
}