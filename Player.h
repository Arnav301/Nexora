#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
    std::string name;
    int health;
    int attack;
    int defense;
    std::vector<std::string> inventory;

public:
    Player(std::string n="Hero", int h=100, int a=15, int d=5);

    std::string getName();
    int getHealth();
    bool isAlive();

    void addItem(std::string item);
    void showInventory();
    void usePotion();

    void takeDamage(int dmg);
    int attackEnemy();
    
    void saveGame();
    void loadGame();
};

#endif
