# 🎮 Text-Based Adventure Game

A simple C++ text adventure game where you explore rooms, battle enemies, collect potions, and save/load progress.
Built using OOP, randomness, and file handling.


# ⚙️ Features

- 🧑 Player system with health, attack, defense, and inventory.

- 👹 Enemies (random encounters like goblins).

- ⚔️ Battle system (attack, potion, run).

- 🎲 Random events (enemy, treasure, trap, empty room).

- 💾 Save & load progress from a file.

# 🚀 How to Compile & Run

## Using g++:

g++ main.cpp Game.cpp Player.cpp Enemy.cpp -o AdventureGame
./AdventureGame

# 🕹️ Gameplay

1. Start the game and enter your hero’s name.
2. Choose actions:

- Explore rooms

- Fight enemies

- Collect and use potions

- Save / load game progress

- Survive as long as you can… or die trying! ☠️

# 📸 Example Run
Enter your hero's name: John
🎮 Welcome, John! Let the adventure begin.

➡ What do you want to do?
1. Explore room
2. Show inventory
3. Use potion
4. Save game
5. Load game
6. Exit
Choice: 1

👹 A wild Goblin appeared!

⚔ Goblin HP: 40 | John HP: 100
Choose: (A)ttack, (P)otion, (R)un: A
🗡 You dealt 18 damage!
💥 John took 7 damage. HP = 93

# 🔧 Requirements
- A C++ compiler (g++, MSVC, clang++)

- Git (if cloning from GitHub)

