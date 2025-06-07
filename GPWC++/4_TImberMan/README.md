# TIMBER MAN Game

A simple 2D game built with C++ and SFML where you control a lumberjack who must chop trees to score points while avoiding falling branches.

## Prerequisites

- C++ compiler (g++ recommended)
- SFML library
- Make (optional, for building)

## SFML Installation Guide

### For Linux (Ubuntu/Debian)

1. Install SFML and its dependencies:

```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

### For Linux (Fedora)

```bash
sudo dnf install SFML SFML-devel
```

### For Linux (Arch Linux)

```bash
sudo pacman -S sfml
```

## Building and Running the Game

### Method 1: Using g++ directly to compile

```bash
g++ timber.cpp -o timber -lsfml-graphics -lsfml-window -lsfml-system
```

### Method 2: Run the game

```bash
./timber
```

## Game Overview

### Controls

- **Left Arrow Key**: Move left and chop
- **Right Arrow Key**: Move right and chop
- **Enter**: Start Game / Restart Game
- **Esc**: Quit Game

### Gameplay

1. The game starts with a title screen.
2. Press Enter to begin.
3. Control the lumberjack at the bottom of the screen & Chop trees by pressing Left/Right arrow keys.
4. Avoid falling branches.
5. Score points for each successful chop.
6. Game ends when you get hit by a branch or timebar reaches end.

### Features

- Score tracking
- Sound effects
- Background music
- Animated sprites
- Collision detection
- Increasing difficulty

## Project Structure

```
TIMBER MAN/
├── timber.cpp          # Main game source code
├── graphics/          # Game graphics assets
├── sound/            # Sound effects and music
├── font/             # Font files
└── README.md         # This file
```

## Troubleshooting

If you encounter any issues:

1. Make sure SFML is properly installed:

```bash
pkg-config --libs sfml-all
```

2. Check if all required assets are present in their respective folders:

   - graphics/
   - sound/
   - font/

3. Verify file permissions:

```bash
chmod +x timber
```

## Credits

- Game assets and sounds are provided with the project
- Built using SFML (Simple and Fast Multimedia Library)
- Developed as part of a C++ programming course

## License

This project is part of an educational course and should be used accordingly.
