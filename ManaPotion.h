#pragma once
#include "Item.h"

class ManaPotion : public Item {
	int manaAmount;

public:
	ManaPotion(int amount);

	void use(Player& player) override;

};