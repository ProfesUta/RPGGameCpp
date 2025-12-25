#include "Item.h"

Item::Item(const std::string& name, ItemType type) : name(name), type(type) {}

Item::~Item() = default;

std::string Item::getName() const {
	return name;
}

ItemType Item::getType() const {
	return type;
}