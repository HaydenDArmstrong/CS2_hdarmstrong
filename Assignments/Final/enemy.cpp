#include "enemy.h"
#include "player.h"
#include <iostream>

Enemy::Enemy(std::string enemyName, int enemyHealth, int enemyDamage)
    : name(enemyName), health(enemyHealth), damage(enemyDamage) {}

void Enemy::attack(Player* player) {
    player->takeDamage(damage);
    std::cout << name << " attacks " << player->getName() 
              << " for " << damage << " damage!" << std::endl;
}

void Enemy::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
    std::cout << name << " takes " << amount << " damage. Current health: " << health << std::endl;
}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}
