# SLAYER!🗡️

A 2D point and click movement survival game developed in C++ using SFML.

## Project Overview

In this game, players must survive waves of zombies and skeletons using a variety of weapons, strategic movement, and quick reflexes. The project demonstrates core OOP concepts, including inheritance, polymorphism, encapsulation, and composition.

## Object-Oriented Design

The game was built with modular class architecture:

- `Game`: Menu navigation and start game logic with the core game loop and state manager.
- `Entity`:  Everything interactive the game itself.
- - `Projectile`: A subclass of `Entity` that is the projectiles fired by every `Character`.
- - `Character`: A subclass of `Entity` that is every `Character` in the game.
- - -`Player`: Subclass of `Charactert` this is you the player that you control.
- - -`Enemy`: Subclass of `Character` containts the enemy AI. 
- - - -`Zombie` : Subclasses of `Enemy` chases you around doing damage on contact.
- - - -`Skeleton` : Subclasses of `Enemy` stays stationary on the screen shooting projectiles at you.
- `Weapon`: Every `Character` holds a weapon which determines the damage they do and the size of projectile.

## 🛠️ Technologies Used

- **Language**: C++  
- **Library**: [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)  
- **Tools**: Git, Visual Studio / VS Code 

## 🎮 How to Play

1. Launch the game with "make files" in the terminal.
2. The **Main Menu** will appear click `Play!`.
3. Choose your weapon in the **Weapons Menu**.
4. Use your right mouse button to move and space to shoot with the mouse position to aim.
5. Survive as long as you can!
6. When defeated, the **Death Screen** will show your stats.
7. You can press continue to play again and beat your high score!

## 🖥️ How to Debug

1. Launch the with "make tests" in the terminal.
2. Various unit tests will be conducted and if there are no errors there will be a confirmation all the tests passed succesfully


## 🧑‍💻 Team Members

- Lilith Jackson
- Isaac Sheehan
- Jason Liang

## Requirements:

- C++17 or newer
- SFML 2.5.1 or later
- CMake (optional)
- Mouse (optional but creates a more fun experience)