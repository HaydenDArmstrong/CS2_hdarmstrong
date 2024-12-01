#pragma once
#include <string>
#include "item.h"
#include "enemy.h"

class Player
{
private:
    std::string name;
    int health;
    int maxHealth;
    Item *inventory[10]; // Inventory array for holding items
    int inventoryCount;  // To keep track of how many items are in the inventory

public:
    // Constructor
    Player(std::string playerName, int startHealth);

    // Combat methods
    void attack(Enemy *enemy);
    void takeDamage(int amount);
    void addToInventory(Item *item); // Add item to inventory
    void useItem(int index);         // Use an item from inventory

    // Getters for player stats and inventory
    Item *getItemFromInventory(int index);
    int getInventoryCount();
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;

    // Setter for health (in case you want to set health)
    void setHealth(int newHealth);
};