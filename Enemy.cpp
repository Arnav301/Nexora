#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(std::string t, int h, int a) : type(t), health(h), attack(a) {}

std::string Enemy::getType() { return type; }
int Enemy::getHealth() { return health; }
bool Enemy::isAlive() { return health > 0; }

void Enemy::takeDamage(int dmg) { health -= dmg; }
int Enemy::attackPlayer() { return attack + (rand() % 5); }
