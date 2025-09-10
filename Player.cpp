#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

Player::Player(string n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {}

string Player::getName() { return name; }
int Player::getHealth() { return health; }
bool Player::isAlive() { return health > 0; }

void Player::addItem(string item) { inventory.push_back(item); }

void Player::showInventory() {
    cout << "\n📦 Inventory: ";
    if (inventory.empty()) cout << "Empty\n";
    else {
        for (size_t i=0; i<inventory.size(); i++) {
            cout << inventory[i] << (i+1 == inventory.size() ? "\n" : ", ");
        }
    }
}

void Player::usePotion() {
    for (size_t i=0; i<inventory.size(); i++) {
        if (inventory[i] == "Potion") {
            health += 30;
            cout << "💊 You used a potion! Health = " << health << "\n";
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
    cout << "⚠ No potion in inventory!\n";
}

void Player::takeDamage(int dmg) {
    int reduced = dmg - defense;
    if (reduced < 0) reduced = 0;
    health -= reduced;
    cout << "💥 " << name << " took " << reduced << " damage. HP = " << health << "\n";
}

int Player::attackEnemy() {
    return attack + (rand() % 6);
}

void Player::saveGame() {
    ofstream out("save.txt");
    out << name << " " << health << " " << attack << " " << defense << "\n";
    out << inventory.size() << "\n";
    for (auto &item : inventory) out << item << "\n";
    out.close();
    cout << "💾 Game saved!\n";
}

void Player::loadGame() {
    ifstream in("save.txt");
    if (!in) {
        cout << "⚠ No save file found.\n";
        return;
    }
    int invSize;
    in >> name >> health >> attack >> defense;
    in >> invSize;
    inventory.clear();
    for (int i=0; i<invSize; i++) {
        string item;
        in >> item;
        inventory.push_back(item);
    }
    in.close();
    cout << "✅ Game loaded! Welcome back, " << name << "\n";
}
