#pragma once
#include <string>

class Enemy {
private:
    std::string name;
    int maxHP;
    int currentHP;
    int attackPower;
    int xpReward;

public:
    Enemy(std::string n, int hp, int atk, int xp);

    std::string getName() const;
    int getHP() const;
    int getAttack() const;
    int getXPReward() const;

    void takeDamage(int dmg);
    bool isAlive() const;
};
