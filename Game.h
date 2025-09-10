#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"

class Game {
    Player player;
public:
    Game(std::string playerName);
    void start();
    void exploreRoom();
    void battle(Enemy &enemy);
};

#endif
