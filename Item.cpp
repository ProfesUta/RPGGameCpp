#include "Item.h"

Item::Item(std::string n) : name(n) {}

std::string Item::getName() const {
	return name;
}