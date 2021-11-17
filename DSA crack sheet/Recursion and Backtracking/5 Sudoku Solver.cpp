/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Sample Sudoku for you to get the logic for its solution:




Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Your Task:
You need to complete the two functions:
SolveSudoku(): Takes a grid as its argument and returns true if a solution is possible and false if it is not.
printGrid(): Takes a grid as its argument and prints the 81 numbers of the solved Sudoku in a single line with space separation.


Expected Time Complexity: O(9N*N).
Expected Auxiliary Space: O(N*N).


Constraints:
0 ≤ grid[i][j] ≤ 9


*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int N = 9;
bool is_safe(int grid[9][9], int no, int i, int j)
{
    for (int x = 0; x < 9; x++)
    {
        if (grid[i][x] == no || grid[x][j] == no)
        {
            return false;
        }
    }
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (grid[x][y] == no)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve_soduku(int grid[9][9], int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return solve_soduku(grid, i + 1, 0);
    }
    if (grid[i][j] != 0)
    {
        return solve_soduku(grid, i, j + 1);
    }
    for (int no = 1; no <= 9; no++)
    {
        if (is_safe(grid, no, i, j))
        {
            grid[i][j] = no;
            if (solve_soduku(grid, i, j + 1))
            {
                return true;
            }
        }
    }
    grid[i][j] = 0;
    return false;
}
bool SolveSudoku(int grid[N][N])
{
    // Your code here
    return solve_soduku(grid, 0, 0);
}

//Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    // Your code here
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}
