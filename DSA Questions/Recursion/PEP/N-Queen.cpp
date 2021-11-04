#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool isSafe(vector<vector<bool>> &chess, int row, int col)
{
    for (int i = row - 1, j = col; i >= 0; i--)
    {
        if (chess[i][j])
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j])
            return false;
    }
    for (int i = row - 1, j = col + 1; i > 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j])
            return false;
    }

    return true;
}
void helper(vector<vector<bool>> &chess, int N, int row, string ans)
{
    if (row == chess.size())
    {
        cout << ans << en;
        return;
    }
    for (int col = 0; col < chess[0].size(); col++)
    {
        if (isSafe(chess, row, col))
        {
            chess[row][col] = true;
            helper(chess, N, row + 1, ans + to_string(row) + "-" + to_string(col) + ",");
            chess[row][col] = false;
        }
    }
}
void sol(int N)
{
    vector<vector<bool>> chess(N, vector<bool>(N));
    helper(chess, N, 0, "");
}
int main()
{
    FAST;
    int N;
    cin >> N;
    sol(N);
    return 0;
}