# SLAYER!🗡️

A 2D point and click movement survival game developed in C++ using SFML.

## Project Overview

In this game, players must survive waves of zombies and skeletons using a variety of weapons, strategic movement, and quick reflexes. The project demonstrates core OOP concepts, including inheritance, polymorphism, encapsulation, and composition.

## Object-Oriented Design

The game was built with modular class architecture:

- `Game`: Menu navigation and start game logic with the core game loop and state manager  
- `Entity`:  
- - `Projectile`: 
- - `Character`: 
- - -`Player`:   
- - -`Enemy`: Enemy AI and collision logic 
- - - -`Zombie` : Subclasses of Enemy chases you around doing damage on contact
- - - -`Skeleton` : Subclasses of Enemy stays stationary on the screen shooting projectiles at you
- `Weapon`: Every Character holds a weapon which determines the damage they do


## 🛠️ Technologies Used

- **Language**: C++  
- **Library**: [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)  
- **Tools**: Git, Visual Studio / VS Code 

## 🎮 How to Play

1. Launch the game.
2. The **Main Menu** will appear click `Play!`.
3. Choose your weapon in the **Weapons Menu**.
4. Use your right mouse button to move and space to shoot with the mouse position to aim.
5. Survive as long as you can!
6. When defeated, the **Death Screen** will show your stats.

## 🧑‍💻 Team Members

- Lilith Jackon
- Isaac Sheehan
- Jason Liang

## Requirements:

- C++17 or newer
- SFML 2.5.1 or later
- CMake (optional)