#pragma once
#include <string>
#include "enemy.h"
#include "item.h"

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    Item* inventory[10];
    int inventoryCount;

public:
    Player(std::string playerName, int startHealth);
    
    void attack(Enemy* enemy);
    void takeDamage(int amount);
    void addToInventory(Item* item);
    void useItem(int index);
    
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
};