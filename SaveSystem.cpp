#include "SaveSystem.h"
#include "ItemDatabase.h"

#include <fstream>
#include <iostream>

void SaveSystem::save(const Player& player, const std::string& filename)
{
	std::ofstream file(filename);
	if (!file)
	{
		std::cout << "Failed to save game.\n";
		return;
	}

	file << player.getName() << "\n";
	file << player.getLevel() << " "
		<< player.getXp() << " "
		<< player.getHp() << " "
		<< player.getMaxHp() << " "
		<< player.getGold() << "\n";


	file << player.getInventorySize() << "\n";

	for (const auto& item : player.getInventory()) {
		file << static_cast<int>(item->getID()) << "\n";
	}

	std::cout << "Game saved successfully.\n";

}

bool SaveSystem::load(Player& player, const std::string& filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "No save file found.\n";
		return false;
	}

	std::string name;
	int level, xp, hp, maxHp, gold;

	file >> name;
	file >> level >> xp >> hp >> maxHp >> gold;

	player.setFromSave(name, level, xp, hp, maxHp, gold);

	int invSize;
	file >> invSize;

	for (int i = 0; i < invSize; i++)
	{
		int id;
		file >> id;
		player.addItem(ItemDatabase::createItem(static_cast<ItemID>(id)));
	}

	std::cout << "Game Loaded Successfully.\n";
	return true;
}