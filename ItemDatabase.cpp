#include "ItemDatabase.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

std::unique_ptr<Item> ItemDatabase::createItem(ItemID id) {
	switch (id)
	{
	case ItemID::HEALTH_POTION:
		return createHealthPotion();
	case ItemID::MANA_POTION:
		return createManaPotion();
	default:
		return nullptr;
	}
}

std::unique_ptr<Item> ItemDatabase::createHealthPotion() {
	return std::make_unique<HealthPotion>();
}

std::unique_ptr<Item> ItemDatabase::createManaPotion() {
	return std::make_unique<ManaPotion>();
}