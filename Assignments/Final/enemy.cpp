#include "enemy.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(std::string enemyName, std::string enemyFlavor, int enemyHealth, int enemyDamage, int enemyfleeChance)
{
    name = enemyName;
    flavor = enemyFlavor;
    health = enemyHealth;
    damage = enemyDamage;
    fleeChance = enemyfleeChance;
}

void Enemy::attack(Player *player)
{
    // Generate random damage between 0 and the enemy's damage value
    int randomDamage = rand() % (damage + 1); // rand() % (damage + 1) generates a number between 0 and max damage value
    if (randomDamage >= 1)
    {
        std::cout << name << " attacks " << player->getName()
                  << " back for " << randomDamage << " damage." << std::endl;
    }
    if (randomDamage == 0)
    {
        std::cout << name << " attempted to attack " << player->getName()
                  << ", but was unable to land a blow. " << randomDamage << " damage was dealt." << std::endl;
    }
    player->takeDamage(randomDamage); // Apply damage to the player
}

void Enemy::takeDamage(int amount)
{
    health -= amount;
    if (health < 0)
        health = 0;
    std::cout << name << " takes " << amount << " damage. Enemy health: " << health << std::endl;
}

std::string Enemy::getName() const
{
    return name;
}

std::string Enemy::getFlavor()
{
    return flavor;
}

int Enemy::getHealth() const
{
    return health;
}

int Enemy::getfleeChance()
{
    return fleeChance;
}
