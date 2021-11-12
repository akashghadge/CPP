/*
Combinations 1 Queens 
in this question we are expected to place queens as we place the items in  boxes don't need to use the concept of no queen kill other
just place it in two d matrix
here basically we have boxes have choices that is either they place queen or not
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
void sol(int curr, int total, int row, int col, string ans, vector<int> &board)
{
    if (row == total)
    {
        if (curr == total)
        {
            cout << ans << en;
        }
        return;
    }
    int nr = 0;
    int nc = 0;
    string sep = "\0";
    if (col == total - 1)
    {
        nr = row + 1;
        nc = 0;
        sep = "\n";
    }
    else
    {
        nr = row;
        nc = col + 1;
        sep = " ";
    }
    sol(curr + 1, total, nr, nc, ans + "I" + sep, board);
    sol(curr, total, nr, nc, ans + "_" + sep, board);
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<int> chess(N);
    sol(0, N, 0, 0, "", chess);
    return 0;
}