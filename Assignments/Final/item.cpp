#include "item.h"
#include "player.h"
#include <iostream>

Item::Item(std::string itemName, int itemEffect)
{
    name = itemName;
    effect = itemEffect;
}

void Item::use(Player *player)
{
    int currentHealth = player->getHealth();
    int maxHealth = player->getMaxHealth();
    if (effect > 0)
    {
        // potion. all potions in game heal

        if (currentHealth + effect <= maxHealth)
        {
            // Normal healing when not exceeding max health
            player->setHealth(currentHealth + effect);
            std::cout << "Used " << name << ". Healed for " << effect << " health." << std::endl;
        }
        else if (maxHealth > currentHealth)
        // if current health is not max but current health and the potion is more than max
        {
            int newPotionAmount = maxHealth - currentHealth;
            player->setHealth(currentHealth + newPotionAmount);
            std::cout << "Used " << name << ". Healed for " << newPotionAmount << " health." << std::endl;
        }
        else
        {
            std::cout << "Health is full. " << player->getName() << " wasted a potion." << std::endl;
        }
    }
    else if (effect == 0)
    {
        std::cout << name << " had no efect." << std::endl;
    }
    else
    { // mysterious liquid
        player->setHealth(currentHealth + effect);
        std::cout << name << " damaged you!" << "you lost " << effect << " health." << std::endl;
    }
}

std::string Item::getName() const
{
    return name;
}
