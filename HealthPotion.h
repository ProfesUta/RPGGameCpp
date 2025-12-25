#pragma once
#include "Item.h"

class HealthPotion : public Item {
private:
	int healAmount;

public:
	HealthPotion(int heal);
	void use(Player& player) override;
};