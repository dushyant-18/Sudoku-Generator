#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 9;

// Function to check if a number can be placed in the given position
bool isValid(const vector<vector<int>> &grid, int row, int col, int num)
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
                vector<int> numbers(N);
                iota(numbers.begin(), numbers.end(), 1);
                random_device rd;
                mt19937 g(rd());
                shuffle(numbers.begin(), numbers.end(), g);

                for (int num : numbers)
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

// Backtracking solver to count the number of solutions
bool solveSudoku(vector<vector<int>> &grid, int &count)
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
                        if (solveSudoku(grid, count))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    count++;
    return count > 1;
}

// Function to check if the Sudoku puzzle has a unique solution
bool hasUniqueSolution(vector<vector<int>> grid)
{
    int count = 0;
    solveSudoku(grid, count);
    return count == 1;
}

// Count the number of clues in the grid
int countClues(const vector<vector<int>> &grid)
{
    int count = 0;
    for (const auto &row : grid)
    {
        count += count_if(row.begin(), row.end(), [](int val)
                          { return val != 0; });
    }
    return count;
}
