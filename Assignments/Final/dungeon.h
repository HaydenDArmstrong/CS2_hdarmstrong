#pragma once
#include "room.h"

class Dungeon
{
private:
    Room *firstRoom;

public:
    Dungeon();
    ~Dungeon();

    void createDungeon();
    Room *getFirstRoom();
};