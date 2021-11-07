/*
Permutations 1 Queens 
in this question we are expected to place queens as we place the items in  boxes don't need to use the concept of no queen kill other
just place it in two d matrix   
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
void print(vector<vector<int>> board)
{
    for (auto list : board)
    {
        for (auto val : list)
        {
            cout << val << " ";
        }
        cout << en;
    }
    cout << en;
}
void sol(int curr, int total, vector<vector<int>> &board)
{
    if (curr >= total)
    {
        print(board);
        return;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = curr + 1;
                sol(curr + 1, total, board);
                board[i][j] = 0;
            }
        }
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<vector<int>> chess(N, vector<int>(N));
    sol(0, N, chess);
    return 0;
}