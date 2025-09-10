#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Enter your hero's name: ";
    cin >> name;

    Game game(name);
    game.start();

    return 0;
}
