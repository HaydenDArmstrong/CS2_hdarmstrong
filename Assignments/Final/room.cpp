#include "room.h"

Room::Room(std::string roomDescription, std::string roomFlavor)
{
    flavor = roomFlavor;
    description = roomDescription;
    enemy = nullptr;
    item = nullptr;
    nextRoom = nullptr;
}

void Room::setEnemy(Enemy *roomEnemy)
{
    enemy = roomEnemy;
}

void Room::setItem(Item *roomItem)
{
    item = roomItem;
}

void Room::setNextRoom(Room *next)
{
    nextRoom = next;
}

std::string Room::getDescription() const
{
    return description;
}
std::string Room::getroomFlavor() const
{
    return flavor;
}

Enemy *Room::getEnemy()
{
    return enemy;
}

Item *Room::getItem()
{
    return item;
}

Room *Room::getNextRoom()
{
    return nextRoom;
}

void Room::removeEnemy()
{
    delete enemy;
    enemy = nullptr;
}