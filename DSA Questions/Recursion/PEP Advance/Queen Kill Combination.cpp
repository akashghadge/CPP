/*
this question is same as perior queen P 1 but here we need to take care of killing of queen as well
here we basically using the last cell technicqe
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
int solutions = 0;
void print(vector<vector<int>> board)
{
    for (auto list : board)
    {
        for (auto val : list)
        {
            val ? cout << "q" : cout << "\t";
        }
        cout << en;
    }
    cout << en;
}
bool isSafe(vector<vector<int>> &chess, int row, int col)
{
    // for top side
    for (int i = row, j = col; i >= 0; i--)
        if (chess[i][j] != 0)
            return false;
    // for bottom side
    for (int i = row, j = col; i < chess.size(); i++)
        if (chess[i][j] != 0)
            return false;
    // for left side
    for (int i = row, j = col; j >= 0; j--)
        if (chess[i][j] != 0)
            return false;
    // for left side
    for (int i = row, j = col; j < chess.size(); j++)
        if (chess[i][j] != 0)
            return false;

    // for left dig
    for (int i = row, j = col; i < chess.size() && j >= 0; i++, j--)
        if (chess[i][j] != 0)
            return false;

    for (int i = row, j = col; i >= 0 && j < chess.size(); i--, j++)
        if (chess[i][j] != 0)
            return false;

    for (int i = row, j = col; i < chess.size() && j < chess.size(); i++, j++)
        if (chess[i][j] != 0)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (chess[i][j] != 0)
            return false;

    return true;
}
void sol(int curr, int total, vector<vector<int>> &chess, int cell)
{
    if (curr >= total)
    {
        cout << "Answers :" << en;
        print(chess);
        solutions++;
        return;
    }
    for (int i = cell + 1; i < chess.size() * chess.size(); i++)
    {
        int row = i / chess.size();
        int col = i % chess.size();
        if (isSafe(chess, row, col) && chess[row][col] == 0)
        {
            chess[row][col] = 1;
            sol(curr + 1, total, chess, row * chess.size() + col);
            chess[row][col] = 0;
        }
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<vector<int>> chess(N, vector<int>(N));
    sol(0, N, chess, 0);
    cout << "Total Solutions :" << solutions << en;
    return 0;
}