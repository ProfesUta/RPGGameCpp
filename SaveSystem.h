#pragma once
#include <string>
#include "Player.h"

class SaveSystem {
public:
    static void save(const Player& player, const std::string& filename);
    static bool load(Player& player, const std::string& filename);
};
