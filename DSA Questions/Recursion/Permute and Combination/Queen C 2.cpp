/*
here we doing this using the permutation 1 approch i.e we basically making the n n-1 n-2 choices
so we are giving the choice to queen i.e on level we are having the items and options are boxes okay
but here one catch 
we need make choices after current element so we are passing the prev also
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
void print(vector<vector<bool>> board)
{
    for (auto list : board)
    {
        for (auto val : list)
        {
            !val ? cout << "_" : cout << "I";
        }
        cout << en;
    }
    cout << en;
}
void sol(int curr, int total, vector<vector<bool>> chess, int row, int col)
{
    if (curr >= total)
    {
        cout << "Answer :" << en;
        print(chess);
        return;
    }
    // for remaining row elements
    for (int i = col + 1; i < chess.size(); i++)
    {
        if (chess[row][i] == false)
        {
            chess[row][i] = true;
            sol(curr + 1, total, chess, row, i);
            chess[row][i] = false;
        }
    }
    for (int i = row + 1; i < chess.size(); i++)
    {
        for (int j = 0; j < chess.size(); j++)
        {
            if (chess[i][j] == false)
            {
                chess[i][j] = true;
                sol(curr + 1, total, chess, i, j);
                chess[i][j] = false;
            }
        }
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<vector<bool>> chess(N, vector<bool>(N));
    sol(0, N, chess, 0, -1);
    return 0;
}