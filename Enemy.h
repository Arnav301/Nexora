#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
    std::string type;
    int health;
    int attack;

public:
    Enemy(std::string t, int h, int a);

    std::string getType();
    int getHealth();
    bool isAlive();

    void takeDamage(int dmg);
    int attackPlayer();
};

#endif
