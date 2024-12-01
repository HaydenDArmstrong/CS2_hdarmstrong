#pragma once
#include <string>

class Player;  // Forward declaration

class Enemy {
private:
    std::string name;
    int health;
    int damage;

public:
    Enemy(std::string enemyName, int enemyHealth, int enemyDamage);
    
    void attack(Player* player);
    void takeDamage(int amount);
    
    std::string getName() const;
    int getHealth() const;
};