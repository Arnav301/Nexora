#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(string playerName) : player(playerName) {}

void Game::start() {
    srand(time(0));
    cout << "🎮 Welcome, " << player.getName() << "! Let the adventure begin.\n";
    
    char choice;
    while (player.isAlive()) {
        cout << "\n➡ What do you want to do?\n"
             << "1. Explore room\n"
             << "2. Show inventory\n"
             << "3. Use potion\n"
             << "4. Save game\n"
             << "5. Load game\n"
             << "6. Exit\n"
             << "Choice: ";
        cin >> choice;

        switch(choice) {
            case '1': exploreRoom(); break;
            case '2': player.showInventory(); break;
            case '3': player.usePotion(); break;
            case '4': player.saveGame(); break;
            case '5': player.loadGame(); break;
            case '6': return;
            default: cout << "⚠ Invalid choice.\n";
        }
    }
    cout << "☠ You died. Game over!\n";
}

void Game::exploreRoom() {
    int event = rand() % 100;
    if (event < 40) {
        Enemy enemy("Goblin", 40, 10);
        cout << "\n👹 A wild " << enemy.getType() << " appeared!\n";
        battle(enemy);
    } else if (event < 70) {
        cout << "\n💰 You found a potion!\n";
        player.addItem("Potion");
    } else if (event < 85) {
        cout << "\n💥 You triggered a trap! -20 HP\n";
        player.takeDamage(20);
    } else {
        cout << "\n😌 The room is empty.\n";
    }
}

void Game::battle(Enemy &enemy) {
    while (enemy.isAlive() && player.isAlive()) {
        cout << "\n⚔ " << enemy.getType() << " HP: " << enemy.getHealth()
             << " | " << player.getName() << " HP: " << player.getHealth() << "\n";
        cout << "Choose: (A)ttack, (P)otion, (R)un: ";
        char c; cin >> c;

        if (c == 'A' || c == 'a') {
            int dmg = player.attackEnemy();
            enemy.takeDamage(dmg);
            cout << "🗡 You dealt " << dmg << " damage!\n";
        } else if (c == 'P' || c == 'p') {
            player.usePotion();
        } else if (c == 'R' || c == 'r') {
            cout << "🏃 You ran away!\n";
            return;
        }

        if (enemy.isAlive()) {
            int edmg = enemy.attackPlayer();
            player.takeDamage(edmg);
        }
    }
    if (!enemy.isAlive()) cout << "✅ You defeated the " << enemy.getType() << "!\n";
}
