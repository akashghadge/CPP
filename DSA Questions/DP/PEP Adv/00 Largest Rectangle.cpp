/*
have gride
find largest squar of 1's

0 0 0 0
1 1 1 1
1 1 1 1
1 1 1 1 
here max sqaure is 3
note :- we need to find the squre not the reactanle
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int max_rectangle(vii &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vii dp(n, vi(m));
    int ans = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    { 
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid[i][j] == 0 || i == n - 1 || j == m - 1)
                dp[i][j] = grid[i][j];
            else
            {
                int temp_min = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = 1 + min(temp_min, dp[i + 1][j + 1]);
            }
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}
int main()
{
    FAST;
    int N, M;
    cin >> N >> M;
    vector<vi> grid(N, vi(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << max_rectangle(grid) << en;
    return 0;
}