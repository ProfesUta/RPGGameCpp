#include "Item.h"

Item::Item(const std::string& name, ItemID id) : name(name), id(id) {}

std::string Item::getName() const {
	return name;
}

ItemID Item::getID() const {
	return id;
}