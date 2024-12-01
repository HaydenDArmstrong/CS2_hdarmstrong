#pragma once
#include <string>
#include "enemy.h"
#include "item.h"

class Room {
private:
    std::string description;
    Enemy* enemy;
    Item* item;
    Room* nextRoom;

public:
    Room(std::string roomDescription);
    
    void setEnemy(Enemy* roomEnemy);
    void setItem(Item* roomItem);
    void setNextRoom(Room* next);
    
    std::string getDescription() const;
    Enemy* getEnemy();
    Item* getItem();
    Room* getNextRoom();
    
    void removeEnemy();
};