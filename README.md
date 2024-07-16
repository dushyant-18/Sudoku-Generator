# Sudoku Generator

This project is a Sudoku puzzle generator written in C++. It creates a valid, solvable Sudoku puzzle with a specified level of difficulty by removing a certain number of digits from a fully populated grid.

## Features

- Generates a complete, valid Sudoku grid.
- Shuffles rows and columns within each 3x3 block to maintain validity while introducing variability.
- Removes random numbers from the grid to create a playable Sudoku puzzle.
- Ensures the generated Sudoku puzzle has a unique solution (for the unique Sudoku generator).
- Difficulty level can be adjusted by changing the number of clues left in the grid.
- Prints the generated Sudoku puzzle to the console.

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Ensure you have the following software installed on your machine:

- C++ compiler (e.g., g++)
- CMake (version 3.10 or higher)
- Git

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/SudokuGenerator.git
    cd SudokuGenerator
    ```

2. Create a build directory and navigate to it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project and generate the build files:
    ```sh
    cmake ..
    ```

4. Build the project using `make`:
    ```sh
    make
    ```

### Running the Project

After building the project, you can run the executable to generate and print a Sudoku puzzle:

```sh
./SudokuGenerator

