# UNO Game

## Overview
This project is a digital version of the classic card game **UNO**, implemented in C++. The game allows multiple players to compete against each other in a turn-based manner, following the traditional rules of UNO. The graphical user interface (GUI) is built using a custom graphics library, creating an interactive and visually appealing gameplay experience.

## Features
- **Multiplayer Support**: Up to 4 players can participate in the game.
- **Graphical Interface**: Uses a graphical library to display players, cards, and game interactions.
- **Card Mechanics**: Implements various UNO card actions such as reverse, skip, draw two, draw four, and wild cards.
- **Turns**: The game logic ensures smooth turn transitions and validates playable moves.
- **Randomized Deck**: The deck is shuffled and distributed at the start of the game.
- **Game State Management**: Handles player actions, turn order, and end-game conditions.

## Technologies Used
- **C++**: Core programming language for game logic and mechanics.
- **Graphics Library**: Handles rendering of game elements (players, cards, UI elements).
- **Object-Oriented Programming (OOP)**: Structured using classes such as `Game`, `Player`, `Cards`, and `UnoCard`.
- **Standard Template Library (STL)**: Utilizes `vector` for managing card decks and players.
- **Memory Management**: Efficient handling of dynamic memory to avoid leaks and ensure smooth performance.

