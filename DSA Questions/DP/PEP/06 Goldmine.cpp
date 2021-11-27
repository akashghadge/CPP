/*
here we have  grid of nums
we can start dig from 0th column and dig to last column
we can dig only -> right direction and 
  -> 2
1 -> 3
  -> 4
we can dig like this i.e 
top right
right
bottom right
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
int gold(vector<vi> &mine)
{
    int n = mine.size();
    int m = mine[0].size();
    vector<vi> dp(n, vi(m));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = mine[i][j];
            else if (j == m - 1)
                dp[i][j] = mine[i][j];
            else if (i == n - 1)
                dp[i][j] = max(dp[i - 1][j + 1], dp[i][j + 1]) + mine[i][j];
            else if (i == 0)
                dp[i][j] = max(dp[i + 1][j + 1], dp[i][j + 1]) + mine[i][j];
            else
            {
                int max_value = max(dp[i + 1][j + 1], dp[i - 1][j + 1]);
                dp[i][j] = max(max_value, dp[i][j + 1]) + mine[i][j];
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i][0]);
    }
    return ans;
}

// gfg clean code
int maxGold(int n, int m, vector<vector<int>> M)
{
    int dp[n][m];
    for (int i = 0; i < n; i++)
        dp[i][m - 1] = M[i][m - 1];

    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            dp[i][j] = M[i][j];
            if (i - 1 >= 0)
                temp = max(dp[i - 1][j + 1], temp);
            if (i + 1 < n)
                temp = max(dp[i + 1][j + 1], temp);
            temp = max(dp[i][j + 1], temp);
            dp[i][j] += temp;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(dp[i][0], ans);
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
    cout << gold(grid) << en;
}