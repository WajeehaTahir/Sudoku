# Sudoku

This C++ program allows you to play Sudoku puzzles and provides solutions for them. You can either start a new game with varying levels of difficulty or load a previously saved game. The game interface is text-based and runs in your console.

## How to Play

1. Clone or download this repository to your local machine.
2. Compile the code using your C++ compiler.
3. Run the compiled executable.
4. Follow the on-screen instructions to choose whether to start a new game or load a saved one.

## Features

- **New Game**: Choose from three difficulty levels - Easy, Intermediate, or Hard. The program generates Sudoku puzzles with varying numbers of hints (provided numbers) based on your selected difficulty level.

- **Load Game**: If you have a saved game, you can load it and continue playing.

- **Gameplay**: When playing, you'll enter row, column, and value inputs to fill in the Sudoku grid. The program will validate your inputs and display the Sudoku board with correct and incorrect inputs highlighted.

- **Save Game**: At any point during the game, you can choose to save your progress and continue later.

- **Game End**: The game ends when you either complete the Sudoku board, reach a certain number of incorrect inputs, or choose to exit. The program will display the number of moves you made.

## Saved Games

The program saves your game progress in three separate files:
- `Solution.txt`: Contains the solution to the Sudoku puzzle.
- `Problem.txt`: Contains the puzzle with some numbers hidden as hints.
- `Moves.txt`: Stores the number of moves made during the game.

## Screenshot
![image](https://github.com/WajeehaTahir/Sudoku/assets/88159584/b3b02d1c-00ee-4d8b-bbeb-07ba3fd11831)
##
_Documented by ChatGPT._
