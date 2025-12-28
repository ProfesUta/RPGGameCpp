#pragma once
#include "Item.h"

class ManaPotion : public Item {
public:
	ManaPotion();
	void use(Player& player) override;
};