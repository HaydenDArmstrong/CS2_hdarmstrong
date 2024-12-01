#include "player.h"
#include <iostream>

Player::Player(std::string playerName, int startHealth) 
    : name(playerName), health(startHealth), maxHealth(startHealth), inventoryCount(0) {
    for (int i = 0; i < 10; ++i) {
        inventory[i] = nullptr;
    }
}

void Player::attack(Enemy* enemy) {
    int damage = 10;  // Base damage
    enemy->takeDamage(damage);
    std::cout << name << " attacks " << enemy->getName() 
              << " for " << damage << " damage!" << std::endl;
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
    std::cout << name << " takes " << amount << " damage. Current health: " << health << std::endl;
}

void Player::addToInventory(Item* item) {
    if (inventoryCount < 10) {
        inventory[inventoryCount++] = item;
        std::cout << "Added " << item->getName() << " to inventory." << std::endl;
    } else {
        std::cout << "Inventory is full!" << std::endl;
    }
}

void Player::useItem(int index) {
    if (index >= 0 && index < inventoryCount) {
        inventory[index]->use(this);
        // Remove item after use
        delete inventory[index];
        for (int i = index; i < inventoryCount - 1; ++i) {
            inventory[i] = inventory[i + 1];
        }
        inventoryCount--;
    }
}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getMaxHealth() const {
    return maxHealth;
}