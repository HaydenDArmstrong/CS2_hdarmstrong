#include "dungeon.h"
#include <iostream>

Dungeon::Dungeon() : firstRoom(nullptr) {}

Dungeon::~Dungeon() {
    Room* current = firstRoom;
    while (current != nullptr) {
        Room* next = current->getNextRoom();
        delete current;
        current = next;
    }
}

void Dungeon::createDungeon() {
    // Create rooms
    Room* entrance = new Room("Dungeon Entrance");
    Room* hallway = new Room("Dark Hallway");
    Room* monsterRoom = new Room("Monster Chamber");
    Room* treasureRoom = new Room("Treasure Room");

    // Create enemies
    Enemy* goblin = new Enemy("Goblin", 30, 5);
    Enemy* ogre = new Enemy("Ogre", 50, 10);

    // Create items
    Item* healthPotion = new Item("Health Potion", 20);
    
    // Set up room connections
    entrance->setNextRoom(hallway);
    entrance->setItem(healthPotion);
    
    hallway->setNextRoom(monsterRoom);
    hallway->setEnemy(goblin);
    
    monsterRoom->setNextRoom(treasureRoom);
    monsterRoom->setEnemy(ogre);

    // Set first room
    firstRoom = entrance;
}

Room* Dungeon::getFirstRoom() {
    return firstRoom;
}