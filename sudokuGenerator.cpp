#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

const int N = 9;

// Function to check if a number can be placed in the given position
bool isValid(vector<vector<int>> &grid, int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Function to generate a completely filled valid Sudoku grid
bool fillGrid(vector<vector<int>> &grid)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (fillGrid(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to shuffle rows within each 3x3 block
void shuffleRows(vector<vector<int>> &grid)
{
    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < 3; i++)
    {
        vector<int> rows = {i * 3, i * 3 + 1, i * 3 + 2};
        shuffle(rows.begin(), rows.end(), g);
        vector<vector<int>> temp = grid;
        for (int j = 0; j < 3; j++)
        {
            grid[i * 3 + j] = temp[rows[j]];
        }
    }
}

// Function to shuffle columns within each 3x3 block
void shuffleCols(vector<vector<int>> &grid)
{
    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < 3; i++)
    {
        vector<int> cols = {i * 3, i * 3 + 1, i * 3 + 2};
        shuffle(cols.begin(), cols.end(), g);
        vector<vector<int>> temp = grid;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < N; k++)
            {
                grid[k][i * 3 + j] = temp[k][cols[j]];
            }
        }
    }
}

// Function to remove random numbers to create a Sudoku puzzle
void removeNumbers(vector<vector<int>> &grid, int count)
{
    random_device rd;
    mt19937 g(rd());

    while (count > 0)
    {
        int cellId = g() % (N * N);
        int row = cellId / N;
        int col = cellId % N;
        if (grid[row][col] != 0)
        {
            grid[row][col] = 0;
            count--;
        }
    }
}

// Function to print the Sudoku grid with blanks
void printGrid(const vector<vector<int>> &grid)
{
    cout << "Generated Sudoku Puzzle:" << endl;
    cout << " -----------------------" << endl;
    for (int row = 0; row < N; row++)
    {
        if (row > 0 && row % 3 == 0)
        {
            cout << "|-------+-------+-------|" << endl;
        }
        for (int col = 0; col < N; col++)
        {
            if (col == 0)
                cout << "| ";
            if (col > 0 && col % 3 == 0)
            {
                cout << "| ";
            }
            if (grid[row][col] == 0)
            {
                cout << "_ ";
            }
            else
            {
                cout << grid[row][col] << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << " -----------------------" << endl;
}

int main()
{
    vector<vector<int>> grid(N, vector<int>(N, 0));

    // Generate a complete Sudoku grid
    fillGrid(grid);

    // Shuffle rows and columns within each 3x3 block
    shuffleRows(grid);
    shuffleCols(grid);

    // Remove random numbers to create a Sudoku puzzle
    int numbersToRemove = 40; // Adjust this number to change the difficulty
    removeNumbers(grid, numbersToRemove);

    // Print the generated Sudoku puzzle
    printGrid(grid);

    return 0;
}
