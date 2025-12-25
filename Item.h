#pragma once
#include <string>

class Player; // Forward declaration

class Item
{
private:
	std::string name;

public:
	Item(std::string n);
	virtual ~Item() = default;
	
	std::string getName() const;

	virtual void use(Player& player) = 0;

};

