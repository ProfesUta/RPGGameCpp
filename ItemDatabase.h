#pragma once
#include <memory>
#include "Item.h"

class ItemDatabase {
public:
	static std::unique_ptr<Item> createItem(ItemID id);
    static std::unique_ptr<Item> createHealthPotion();
	static std::unique_ptr<Item> createManaPotion();
};
