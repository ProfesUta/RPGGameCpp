#pragma once
#include <string>

class Player; // Forward declaration


enum class ItemType
{
	HEALTH_POTION,
	MANA_POTION
};


class Item
{
protected:
	std::string name;
	ItemType type;

public:
	Item(const std::string& name, ItemType type);

	virtual ~Item();

	virtual void use(Player& player) = 0;

	std::string getName() const;
	ItemType getType() const;


};

