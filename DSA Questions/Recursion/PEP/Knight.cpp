#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void printVector(vector<vector<int>> vec)
{
    for (auto list : vec)
    {
        for (auto val : list)
        {
            cout << val << " ";
        }
        cout << en;
    }
    cout << endl;
}
int countAns = 0;
void helper(vector<vector<int>> &board, int row, int col, int N, int move)
{
    if (row < 0 || col < 0 || row >= N || col >= N || board[row][col] > 0)
        return;
    if (move == board.size() * board.size())
    {
        board[row][col] = move;
        // printVector(board);
        countAns++;
        board[row][col] = 0;
        return;
    }

    board[row][col] = move;
    // recursive calls
    helper(board, row - 2, col + 1, N, move + 1);
    helper(board, row - 1, col + 2, N, move + 1);
    helper(board, row + 1, col + 2, N, move + 1);
    helper(board, row + 2, col + 1, N, move + 1);
    helper(board, row + 2, col - 1, N, move + 1);
    helper(board, row + 1, col - 2, N, move + 1);
    helper(board, row - 1, col - 2, N, move + 1);
    helper(board, row - 2, col - 1, N, move + 1);

    board[row][col] = 0;
    return;
}
void sol(int row, int col, int N)
{
    vector<vector<int>> board(N, vector<int>(N));
    helper(board, row, col, N, 1);
}
int main()
{
    // FAST;
    int N;
    cin >> N;
    int row, col;
    cin >> row >> col;
    sol(row, col, N);
    cout << countAns << en;
    return 0;
} 