#pragma once
#include <string>

class Player;  // Forward declaration

class Item {
private:
    std::string name;
    int effect;

public:
    Item(std::string itemName, int itemEffect);
    
    void use(Player* player);
    
    std::string getName() const;
};