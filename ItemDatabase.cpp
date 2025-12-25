#include "ItemDatabase.h"
#include "HealthPotion.h"

std::unique_ptr<Item> ItemDatabase::createHealthPotion() {
    return std::make_unique<HealthPotion>(30);
}
