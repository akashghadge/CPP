/*
9 9
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
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
bool isValid(vector<vector<int>> &sudoku, int row, int col, int num)
{
    // in col check
    for (int i = 0; i < sudoku.size(); i++)
    {
        if (sudoku[i][col] == num)
            return false;
    }
    // in row check
    for (int i = 0; i < sudoku[0].size(); i++)
        if (sudoku[row][i] == num)
            return false;

    int quadX = (col) / 3;
    int quadY = (row) / 3;
    quadX *= 3;
    quadY *= 3;

    for (int i = quadY; i < quadY + 3; i++)
    {
        for (int j = quadX; j < quadX + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}
void printSudoku(vector<vector<int>> sudoku)
{
    for (auto row : sudoku)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << en;
    }
    cout << en;
}
void sol(vector<vector<int>> &sudoku, int row, int col)
{
    if (row == sudoku.size())
    {
        cout << en;
        printSudoku(sudoku);
        return;
    }
    if (sudoku[row][col] != 0)
    {
        if (col + 1 >= sudoku[0].size())
            sol(sudoku, row + 1, 0);
        else
            sol(sudoku, row, col + 1);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isValid(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            // recursive call
            if (col + 1 == sudoku[0].size())
                sol(sudoku, row + 1, 0);
            else
                sol(sudoku, row, col + 1);
            sudoku[row][col] = 0;
        }
    }
}

int main()
{
    // FAST;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sudoku(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> sudoku[i][j];

    sol(sudoku, 0, 0);

    return 0;
}