#include "Enemy.h"

Enemy::Enemy(std::string n, int hp, int atk, int xp) : name(n), maxHP(hp), currentHP(hp), attackPower(atk), xpReward(xp) {}

std::string Enemy::getName() const { return name; }
int Enemy::getHP() const { return currentHP; }
int Enemy::getAttack() const { return attackPower; }
int Enemy::getXPReward() const { return xpReward; }

void Enemy::takeDamage(int dmg) {

    currentHP -= dmg;
    if (currentHP < 0) {

        currentHP = 0;
    }
}

bool Enemy::isAlive() const {

    return currentHP > 0;
}
