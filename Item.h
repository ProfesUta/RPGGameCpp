#pragma once
#include <string>

class Player; // Forward declaration


enum class ItemID
{
	HEALTH_POTION,
	MANA_POTION
};


class Item
{
protected:
	std::string name;
	ItemID id;


public:
	Item(const std::string& name, ItemID id);

	virtual ~Item() = default;

	virtual void use(Player& player) = 0;

	std::string getName() const;
	ItemID getID() const;


};

