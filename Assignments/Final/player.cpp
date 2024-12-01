#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Player::Player(std::string playerName, int startHealth)
{
    name = playerName;
    health = startHealth;
    maxHealth = startHealth;
    inventoryCount = 0;
    for (int i = 0; i < 4; ++i)
    {
        inventory[i] = nullptr; // Set all inventory slots to nullptr
    }
}

void Player::attack(Enemy *enemy)
{
    int damage = rand() % 21; // you deal random damage between 0 and 21
    if (damage > 0)
    {
        std::cout << name << " attacks " << enemy->getName()
                  << " for " << damage << " damage." << std::endl;
    }
    if (damage == 0)
    {
        std::cout << "Your attack misses the enemy, and you try to regain your footing. " << damage << "  damage was dealt." << std::endl;
    }
    enemy->takeDamage(damage);
}

void Player::takeDamage(int amount)
{
    health -= amount;
    if (health < 0)
        health = 0;
    std::cout << name << " takes " << amount << " damage. Your health: " << health << std::endl;
}

void Player::addToInventory(Item *item)
{
    if (inventoryCount < 4)
    {
        inventory[inventoryCount++] = item;
        std::cout << "Added " << item->getName() << " to inventory." << std::endl;
    }
    else
    {
        std::cout << "Inventory is full!" << std::endl;
    }
}

void Player::useItem(int index)
{
    if (index < 0 || index >= inventoryCount || inventory[index] == nullptr)
    {
        std::cout << "Invalid inventory index!" << std::endl;
        return;
    }

    // Store item pointer and use it
    Item *item = inventory[index];
    item->use(this);

    // Shift remaining items
    for (int i = index; i < inventoryCount - 1; i++)
    {
        inventory[i] = inventory[i + 1];
    }

    // Clear last slot and decrease count
    inventoryCount--;
    inventory[inventoryCount] = nullptr;

    // Delete the used item
    delete item;
}

std::string Player::getName() const
{
    return name;
}

int Player::getHealth() const
{
    return health;
}

int Player::getMaxHealth() const
{
    return maxHealth;
}

void Player::setHealth(int newHealth)
{
    if (newHealth < 0)
    {
        health = 0; // Prevent health from going below 0
    }
    else if (newHealth > maxHealth)
    {
        health = maxHealth; // Prevent health from exceeding maxHealth
    }
    else
    {
        health = newHealth;
    }
    std::cout << name << "'s health is now " << health << std::endl;
}

Item *Player::getItemFromInventory(int index)
{
    if (index >= 0 && index < inventoryCount)
    {
        return inventory[index];
    }
    return nullptr;
}

int Player::getInventoryCount()
{
    return inventoryCount;
}
