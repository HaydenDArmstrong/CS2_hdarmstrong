//// Chatgpt was used to help edit and improve flavor text for rooms and enemies.
#include "dungeon.h"
#include "player.h"
#include <iostream>

Dungeon::Dungeon()
{
    firstRoom = nullptr;
}

Dungeon::~Dungeon()
{
    Room *current = firstRoom;
    while (current != nullptr)
    {
        Room *next = current->getNextRoom();
        delete current;
        current = next;
    }
}

void Dungeon::createDungeon()
{
    // rooms
    Room *entrance = new Room(
        "Dungeon Entrance",
        "A Crumbling stone archway looms before you, covered in moss.\n"
        "A musty, damp smell fills the air.\n"
        "A potion lies on the steps. Perhaps dropped by the last adventurer who entered.\n");
    Room *hallway = new Room(
        "Dark Hallway",
        "Flickering torchlight barely helps you wade through the darkness of the corridor.\n"
        "Cobwebs drape from the ceiling, and the floor is littered with fragments of bones and rusted weapons.\n"
        "An oppressive silence weighs heavy, broken only by the occasional distant drip of water.\n");
    Room *hiddenPath = new Room(
        "Nowhere to go?",
        "It seems the path has ended. The room, with the enemy slain, only contains you and small bugs. \n"
        "When looking at these bugs, you sudddenly notice a small hole in the wall.\n"
        "Perhaps the wall can be broken?\n");
    Room *trappedPath = new Room(
        "Normal Hallway",
        "As you walk along the hallway, the ground shifts beneath you; it seems you stepped on a pressure plate. \n"
        "Arrows fly towards you, one skims inches past your face, leaving a small mark. \n"
        "You begin to tread more carefully.\n");
    Room *armorRoom = new Room(
        "Armory",
        "Rows of ancient weapon racks line the walls.\n"
        "Most empty, but a few still holding rusted swords and dented shields.\n "
        "Tattered banners of long-forgotten kingdoms hang in tatters, broken armor lays on the ground. \n "
        "You find a Healing Potion hidden beneath years and years of dust.\n "
        "A pungent smell begins to enter your nose...\n");
    Room *monsterRoom = new Room(
        "Monster Chamber",
        "Massive stone columns rise to a ceiling lost in darkness. Dried bloodstains cover the floor, and claw marks cover the walls.\n"
        "Bones are scattered carelessly, some human, some from creatures unidentifiable.\n"
        "The air is thick with the metallic scent of old violence. You hear a distant clicking.\n");

    Room *illusionRoom = new Room(
        "Mysterious Room?",
        "As you Enter the room, you blink, and as soon as you open your eyes again, you feel the sun blazing on you.\n "
        "You are no longer in a dungeon, but walking on dunes of sand under a big blue sky.\n"
        "Perplexed, you reach for the grains of sand, and find a mysterious vial of liquid hidden underneath.\n"
        "You blink once more, and it seems you are simply back in the dungeon...\n");
    Room *fakeTreasureRoom = new Room(
        "Treasure Room",
        "Golden light seems to emanate from the walls themselves, reflecting off scattered treasures.\n "
        "Jewel-encrusted rings, ancient coins, and glittering artifacts are strewn about.\n"
        "But something feels wrong - the silence is too perfect, the treasures too inviting.\n"
        "In an instant, a booming sound begins to eminate, and coins begin to rattle.\n");

    Room *realTreasureRoom = new Room(
        "True Treasure Room",
        "Past the final foe, Another room filled with treasure is present.\n "
        "Now lacking the feeling of unease, you hold the treasure in your hands.\n"
        "You find a Goblet, one which even an adventurer can imagine holds great value.\n");

    // enemies

    //("name", "flavortext", health, maxdamage, flee chance)
    Enemy *skeleton = new Enemy(
        "Skeleton",
        "A skeletal figure clatters to life, its empty eye sockets glowing faintly as it grips a rusted sword with bony hands. ",
        28, 5, 4);
    Enemy *wall = new Enemy(
        "Wall",
        "It is simply a stone wall. Attacking it is surely the best plan.",
        20, 0, 20);
    Enemy *ogre = new Enemy(
        "Ogre",
        "A hulking figure looms in the shadows, its tusked face twisted in a snarl as it hefts a massive club. A stench eminates from the creature. ",
        55, 7, 10);
    Enemy *demon = new Enemy(
        "Demon",
        "A towering demon stands before you, its glowing eyes burning with malice as smoke curls from its dark, leathery skin. "
        "It is incredibly agile and incredibly intimidating. \n",
        50, 16, 18);
    Enemy *mindControlBug = new Enemy(
        "Mind Control Bug",
        "A small and innocuous bug blocks your path. You are not sure if it is culprit, but you believe it may be the source of the illusion you saw. ",
        2, 1, 1);

    // items
    Item *healthPotion = new Item("Health Potion", 15);
    Item *healthPotion2 = new Item("Dusty Health Potion", 9);
    Item *mysteriousLiquid = new Item("Mysterious Liquid", -5);
    Item *goldenGoblet = new Item("Goblet of Wealth", 0);

    //  room connections
    entrance->setNextRoom(hallway);
    entrance->setItem(healthPotion);

    hallway->setNextRoom(monsterRoom);
    monsterRoom->setEnemy(skeleton);

    monsterRoom->setNextRoom(hiddenPath);
    hiddenPath->setEnemy(wall);
    hiddenPath->setNextRoom(armorRoom);
    armorRoom->setEnemy(ogre);
    armorRoom->setItem(healthPotion2);

    armorRoom->setNextRoom(illusionRoom);

    illusionRoom->setItem(mysteriousLiquid);
    illusionRoom->setEnemy(mindControlBug);
    illusionRoom->setNextRoom(trappedPath);

    trappedPath->setNextRoom(fakeTreasureRoom);
    fakeTreasureRoom->setEnemy(demon);

    fakeTreasureRoom->setNextRoom(realTreasureRoom);
    realTreasureRoom->setItem(goldenGoblet);

    // Set first room
    firstRoom = entrance;
}

Room *Dungeon::getFirstRoom()
{
    return firstRoom;
}