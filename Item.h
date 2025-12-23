#pragma once
#include <string>

enum class ItemType {

	Potion

};

struct Item
{
	std::string name;
	ItemType type;
	int power;
};

