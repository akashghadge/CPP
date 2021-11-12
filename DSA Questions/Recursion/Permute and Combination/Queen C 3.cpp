/*
here we doing this using the permutation 1 approch i.e we basically making the n n-1 n-2 choices
so we are giving the choice to queen i.e on level we are having the items and options are boxes okay
but here one catch 
we need make choices after current element so we are passing the prev also
it is basically same as the Combination 2 but is 2d to 1d
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
void sol(int curr, int total, vector<vector<bool>> chess, int cell)
{
    if (curr >= total)
    {
        cout << "Answer :" << en;
        print(chess);
        return;
    }
    for (int i = cell; i < chess.size() * chess.size(); i++)
    {
        int row = cell / chess.size();
        int col = cell % chess.size();
        chess[row][col] = true;
        sol(curr + 1, total, chess, i);
        chess[row][col] = false;
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<vector<bool>> chess(N, vector<bool>(N));
    sol(0, N, chess, 0);
    return 0;
}