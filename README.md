# Mini Game Project (C++)

Two console-based mini games built with pure C++ to demonstrate loops,
arrays, conditional logic, and game-state management.

## Games

### 1. Tic Tac Toe
- 3x3 board with dynamic rendering
- Win / loss / draw detection
- Score tracking across multiple rounds
- Replay option

### 2. Snake
- Real-time grid movement
- Growing snake, food spawning
- Wall and self-collision detection
- Increasing difficulty
- Replay option

## Concepts Used
- Loops, arrays, conditionals, functions
- 2D arrays for the game board
- Deque for snake body
- Non-blocking keyboard input

## Build & Run

```bash
# Tic Tac Toe
g++ TicTacToe.cpp -o tictactoe
./tictactoe

# Snake
g++ Snake.cpp -o snake
./snake
