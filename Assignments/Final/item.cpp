#include "item.h"
#include "player.h"
#include <iostream>

Item::Item(std::string itemName, int itemEffect)
    : name(itemName), effect(itemEffect) {}

void Item::use(Player* player) {
    if (effect > 0) {
        // Healing item
        int currentHealth = player->getHealth();
        int maxHealth = player->getMaxHealth();
        int newHealth = (currentHealth + effect > maxHealth) ? maxHealth : currentHealth + effect;
        
        std::cout << "Used " << name << ". Healed for " << effect << " health." << std::endl;
    }
}

std::string Item::getName() const {
    return name;
}