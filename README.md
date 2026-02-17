# Console Snake Game (C++)

## Overview
A classic, fully functional Snake game playable directly in the Windows command prompt. 
Written in C++ to demonstrate fundamental game loop concepts: rendering, input handling, and game logic updating.

## Controls
* `W` - Move Up
* `A` - Move Left
* `S` - Move Down
* `D` - Move Right
* `X` - Quit Game

## Features
* **Real-time input handling** using `_kbhit()` and `_getch()` from `<conio.h>`.
* **Smooth rendering** using `<windows.h>` to manipulate the console cursor position (avoiding screen clear flickering).
* Dynamic tail array management and collision detection.

## How to Run

> **Note:** This game relies on Windows-specific headers (`<windows.h>`, `<conio.h>`). It will only compile and run on Windows environments.

### Compilation (using g++ / MinGW)
Open your terminal and run:
```bash
g++ main.cpp -o snake.exe
