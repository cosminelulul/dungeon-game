
![Platform](https://img.shields.io/badge/platform-Windows-blue.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/status-finished-success)

# Dungeon Game

A command-line dungeon exploration game written in **C++** using Object-Oriented Programming principles. This was one of my earliest OOP projects, originally built during my first year of university. It's a simple, exploration puzzle where players navigate a 100 room dungeon to locate the goal room as quickly as possible by catching on colour hints.

##  Gameplay Overview

The player is placed randomly in a 10x10 grid of dungeon rooms. ne of these rooms is randomly selected as the goal room. Movement is done using the WASD keys.

As you move around the dugneon, the  terminal color changes based on your proximity to the goal:

  - **White**: Far away

  - **Green**: Getting closer

 -  **Red**: Very close

  - **Gold**: You've found the goal room!


Once you've finished a run, you can press SPACE after finishing a run to restart and try for a better time.


##  Controls

| Key     | Action         |
|---------|----------------|
| `W`     | Move up        |
| `A`     | Move left      |
| `S`     | Move down      |
| `D`     | Move right     |
| `Space` | Start / Restart the game |


## Tech Stack

- **Language**: C++
- **Platform**: Windows-only (uses `<windows.h>`, `<conio.h>`)
- **Compiler**: MinGW
- **Run via**: `cmd.exe` or similar terminal

##  Getting Started

###  Prerequisites

- Windows OS
- A C++ compiler (e.g., MinGW, Visual Studio)

###  Build & Run

```bash
git clone https://github.com/cosminelulul/dungeon-game.git
cd dungeon-game
g++ main.cpp Game.cpp Player.cpp Room.cpp -o dungeon.exe
./dungeon.exe
```

## Gameplay

![Screenshot1](https://i.ibb.co/Jw85dSFR/Screenshot-1.png)



