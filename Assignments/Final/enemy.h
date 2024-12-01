#pragma once
#include <string>

class Player;

class Enemy
{
private:
    std::string name;
    std::string flavor;
    int health;
    int damage;
    int fleeChance;

public:
    Enemy(std::string enemyName, std::string enemyFlavor, int enemyHealth, int enemyDamage, int enemyfleeChance);

    void attack(Player *player);
    void takeDamage(int amount);

    std::string getName() const;
    int getHealth() const;
    std::string getFlavor();
    int getfleeChance();
};