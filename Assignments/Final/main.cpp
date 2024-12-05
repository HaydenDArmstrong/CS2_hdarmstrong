#include <iostream>
#include "dungeon.h"
#include "player.h"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::string playerName;
    std::string weapon;
    int playerHealth;
    int diffChoice;
    std::cout << " ---------------------------------------------" << std::endl;
    std::cout << "Welcome to the Dungeon!" << std::endl;
    std::cout << " ---------------------------------------------" << std::endl;

    std::cout << "what difficulty would you like?";
    std::cout << "\nOptions:\n1. Easy \n2. Normal \n3. Hard \n4. Expert" << std::endl;
    std::cin >> diffChoice;
    switch (diffChoice)
    {
    case 1:
        playerHealth = 100;
        break;
    case 2:
        playerHealth = 50;
        break;
    case 3:
        playerHealth = 35;
        break;
    case 4:
        playerHealth = 20;
        break;
    default:
        playerHealth = 50;
        break;
    }

    std::cout << "What is your Name? ";
    std::cin >> playerName;
    std::cout << "What is your weapon? ";
    std::cin >> weapon;

    std::cout << std::endl;
    std::cout << "While adventuring, " << playerName << " discovers a dungeon hidden underneath moss. \n"
              << playerName << " is already miles outside of the safety of the town. Deep in the forest, this artifical structure feels unnervingly out of place\n"
                               "In a split second decision, "
              << playerName << " puts aside their fear and reservations. " << playerName << " starts their plunge, in hopes of something great potentially awaiting them." << std::endl;

    // Create player
    Player player(playerName, playerHealth);

    // Create dungeon
    Dungeon dungeon;
    dungeon.createDungeon();

    // Start game loop
    bool gameOver = false;
    Room *currentRoom = dungeon.getFirstRoom();

    while (!gameOver && currentRoom != nullptr)
    {
        // Display room description
        std::cout << "\n------- " << currentRoom->getDescription() << " --------------" << std::endl;
        std::cout << currentRoom->getroomFlavor();
        std::cout << " ---------------------------------------------" << std::endl;

        Item *roomItem = currentRoom->getItem();
        if (roomItem != nullptr)
        {
            player.addToInventory(roomItem);
            currentRoom->setItem(nullptr); // Remove the item from the room
        }

        // Check for enemy
        Enemy *roomEnemy = currentRoom->getEnemy();
        if (roomEnemy != nullptr)
        {
            std::cout << "An enemy appears... " << roomEnemy->getFlavor() << std::endl;
            std::cout << "It is a " << roomEnemy->getName() << "." << std::endl;

            // Combat logic
            while (roomEnemy != nullptr && player.getHealth() > 0)
            {
                std::cout << std::endl;
                std::cout << "-" << playerName << " has " << player.getHealth() << " health and " << player.getInventoryCount() << " item(s) in inventory." << "-";
                std::cout << "\nOptions:\n1. Attack\n2. inventory \n3. Run" << std::endl;
                int choice;
                std::cin >> choice;

                while (std::cin.fail()) // if a number is inot inputted
                {
                    std::cout << "Error. Please enter your valid number choice:";
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cin >> choice;
                }

                switch (choice)
                {
                case 1: // Attack
                    std::cout << playerName << " attacks the " << roomEnemy->getName() << " with their " << weapon << "." << std::endl;
                    player.attack(roomEnemy);
                    std::cout << std::endl;
                    if (roomEnemy->getHealth() > 0)
                    {
                        if (roomEnemy->getName() == "Wall")
                        {
                            std::cout << "The wall crumbles.." << std::endl;
                        }
                        else
                        {
                            roomEnemy->attack(&player);
                        }
                    }
                    break;
                case 2:
                    std::cout << playerName << "'s Inventory: \n";
                    // Display the player's inventory
                    for (int i = 0; i < player.getInventoryCount(); ++i)
                    {
                        Item *item = player.getItemFromInventory(i);
                        if (item != nullptr)
                        {
                            std::cout << i + 1 << ". " << item->getName() << std::endl;
                        }
                    }

                    std::cout << "Enter the number of the item you want to use (or 0 to go back): ";
                    int itemChoice;
                    std::cin >> itemChoice;

                    if (itemChoice > 0 && itemChoice <= player.getInventoryCount() &&
                        player.getItemFromInventory(itemChoice - 1) != nullptr)
                    {
                        player.useItem(itemChoice - 1); // Use the chosen item
                    }
                    else if (itemChoice == 0)
                    {
                        std::cout << "Going back to combat." << std::endl;
                    }
                    else
                    {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                    break;
                case 3: // Run
                        // Prompt the player for confirmation
                    std::cout << "Are you sure you want to run? There is a chance the enemy might kill you as you flee. (y/n): ";
                    char fleeChoice;
                    std::cin >> fleeChoice;

                    if (fleeChoice == 'y' || fleeChoice == 'Y')
                    {
                        if (roomEnemy->getName() == "Wall")
                        {
                            std::cout << std::endl;
                            std::cout << "With no other path, and the fear of the wall overpowering you, " << playerName << " runs out of the dungeon.\n"
                                      << playerName << "'s head is filled with hopes of a comfortable cottage where you can rest.\n"
                                                       "But suddenly, you trip on a stone on your ascent, and bleed out. Nobody is there to help as mice scurry around you."
                                      << std::endl;
                            player.setHealth(0);
                            break;
                        }
                        else
                        {
                            // Random chance for the player to be killed
                            int fleeChance = 1 + std::rand() % 21; // Random number between 0 and 20
                            if (fleeChance < roomEnemy->getfleeChance())
                            { // chance of dying according to enemyFleeChance. if flee chance is 20, you cannot flee
                                std::cout << "As you attempt to flee, the " << roomEnemy->getName() << " strikes and kills you. " << playerName << " bleeds out and dies." << std::endl;
                                std::cout << "(Your survival roll was " << fleeChance << ". " << playerName << " cannot escape from " << roomEnemy->getName() << " with less than a " << roomEnemy->getfleeChance() << ".)" << std::endl;
                                player.setHealth(0); // Player dies
                                break;
                            }
                            else
                            {
                                std::cout << "(your survival roll was " << fleeChance << ". " << playerName << " escaped from " << roomEnemy->getName() << " by rolling more or equal to " << roomEnemy->getfleeChance() << ".)" << std::endl;
                                std::cout << playerName << " successfully fleed from the enemy!" << std::endl;
                                roomEnemy = nullptr; // Remove the enemy
                                break;
                            }
                        }
                    }
                    else
                    {
                        std::cout << playerName << " decided not to flee." << std::endl;
                        break;
                    }
                default:
                    std::cout << "Invalid input.\n";
                    break;
                }

                if (roomEnemy != nullptr && roomEnemy->getHealth() <= 0)
                {
                    std::cout << roomEnemy->getName() << " defeated!" << std::endl;
                    currentRoom->removeEnemy();
                    roomEnemy = nullptr;
                }
            }
        }

        // Player died
        if (player.getHealth() <= 0)
        {
            std::cout << "Game Over! You have been defeated." << std::endl;
            gameOver = true;
            break;
        }

        // Move to next room
        std::cout << " ------------------------------------------" << std::endl;
        std::cout << "Do you want to proceed to the next room? (y/n): ";
        char proceed;
        std::cin >> proceed;

        if (proceed != 'n' && proceed != 'N') // failsafe incase user spams, doesnt quit
        {
            currentRoom = currentRoom->getNextRoom();
            std::cout << "\033[2J\033[1;1H";

            // Check for final room (victory condition)
            if (currentRoom == nullptr)
            {
                std::cout << playerName << " scales back up the dungeon, now daydreaming of returning to the city and its merchants, and receiving unimaginable wealth." << std::endl;
                std::cout << "Congratulations! You have completed the dungeon!" << std::endl;
                gameOver = true;
            }
        }
        else
        {
            std::cout << playerName << " quickly runs out of the dungeon with tears in their eyes. " << playerName << "'s head is filled with hopes of a comfortable cottage where they can rest." << std::endl;
            gameOver = true;
        }
    }

    return 0;
}