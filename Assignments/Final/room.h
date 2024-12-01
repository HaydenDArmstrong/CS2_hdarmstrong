#pragma once
#include <string>
#include "enemy.h"
#include "item.h"

class Room
{
private:
    std::string description;
    std::string flavor;
    Enemy *enemy;
    Item *item;
    Room *nextRoom;

public:
    Room(std::string roomDescription, std::string roomFlavor);

    void setEnemy(Enemy *roomEnemy);
    void setItem(Item *roomItem);
    void setNextRoom(Room *next);

    std::string getDescription() const;
    std::string getroomFlavor() const;
    Enemy *getEnemy();
    Item *getItem();
    Room *getNextRoom();

    void removeEnemy();
};