/*
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



 

Example 1:

Input:
1
Output:
[1]
Explaination:
Only one queen can be placed 
in the single cell available.
Example 2:

Input:
4
Output:
[2 4 1 3 ] [3 1 4 2 ]
Explaination:
These are the 2 possible solutions.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function nQueen() which takes n as input parameter and returns a list containing all the possible chessboard configurations in sorted order. Return an empty list if no solution exists.

 

Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 

 

Constraints:
1 ≤ n ≤ 10 


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
bool isSafe(vector<vector<int>> &board, int x, int y, int N)
{
    int n = board.size();
    for (int i = 0; i < y; i++)
    {
        if (board[x][i] == 1)
        {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = x, j = y; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void backtracking(vector<vector<int>> &board, int col, int N, vector<vector<int>> &result)
{
    if (col >= N)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                {
                    v.push_back(j + 1);
                }
            }
        }
        result.push_back(v);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N) == true)
        {
            board[i][col] = 1;
            backtracking(board, col + 1, N, result);
            board[i][col] = 0;
        }
    }
    return;
}
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));

    backtracking(board, 0, n, result);

    sort(result.begin(), result.end());

    return result;
}
int main()
{
    FAST;

    return 0;
}