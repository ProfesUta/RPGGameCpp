#include "ItemDatabase.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

std::unique_ptr<Item> ItemDatabase::createHealthPotion() {
    return std::make_unique<HealthPotion>(30);
}

std::unique_ptr<Item> ItemDatabase::createManaPotion() {
    return std::make_unique<ManaPotion>(20);
}