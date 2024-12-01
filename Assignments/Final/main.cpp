#include <iostream>
#include "dungeon.h"
#include "player.h"

int main() {
    std::cout << "Welcome to the Dungeon Adventure!" << std::endl;
    
    // Create player
    Player player("Hero", 100);
    
    // Create dungeon
    Dungeon dungeon;
    dungeon.createDungeon();
    
    // Start game loop
    bool gameOver = false;
    Room* currentRoom = dungeon.getFirstRoom();
    
    while (!gameOver && currentRoom != nullptr) {
        // Display room description
        std::cout << "\n--- " << currentRoom->getDescription() << " ---" << std::endl;
        
        // Check for enemy
        Enemy* roomEnemy = currentRoom->getEnemy();
        if (roomEnemy != nullptr) {
            std::cout << "An enemy appears: " << roomEnemy->getName() << std::endl;
            
            // Combat logic
            while (roomEnemy != nullptr && player.getHealth() > 0) {
                std::cout << "\nOptions:\n1. Attack\n2. Use Item\n3. Run" << std::endl;
                int choice;
                std::cin >> choice;
                
                switch(choice) {
                    case 1: // Attack
                        player.attack(roomEnemy);
                        if (roomEnemy->getHealth() > 0) {
                            roomEnemy->attack(&player);
                        }
                        break;
                    case 2: // Use Item
                        // Placeholder for item usage
                        break;
                    case 3: // Run
                        roomEnemy = nullptr;
                        break;
                }
                
                if (roomEnemy != nullptr && roomEnemy->getHealth() <= 0) {
                    std::cout << "Enemy defeated!" << std::endl;
                    currentRoom->removeEnemy();
                    roomEnemy = nullptr;
                }
            }
        }
        
        // Player died
        if (player.getHealth() <= 0) {
            std::cout << "Game Over! You have been defeated." << std::endl;
            gameOver = true;
            break;
        }
        
        // Move to next room
        std::cout << "Do you want to proceed to the next room? (y/n): ";
        char proceed;
        std::cin >> proceed;
        
        if (proceed == 'y' || proceed == 'Y') {
            currentRoom = currentRoom->getNextRoom();
            
            // Check for final room (victory condition)
            if (currentRoom == nullptr) {
                std::cout << "Congratulations! You have completed the dungeon!" << std::endl;
                gameOver = true;
            }
        } else {
            gameOver = true;
        }
    }
    
    return 0;
}