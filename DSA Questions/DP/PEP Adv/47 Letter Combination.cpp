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
int unique_nums(int n)
{
    vii dp(n + 1, vi(10, 0));
    vii possible = {
        {0, 8},
        {1, 2, 4},
        {1, 2, 3, 5},
        {2, 3, 6},
        {1, 4, 5, 7},
        {2, 4, 5, 6, 8},
        {3, 5, 6, 9},
        {4, 7, 8},
        {5, 7, 8, 9, 0},
        {6, 8, 9},
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            for (auto p : possible[j])
            {
                dp[i][j] += dp[i - 1][p];
            }
        }
    }
    long long sum = 0;
    sum += accumulate(dp[n].begin(), dp[n].end(), 0);
    return sum;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << unique_nums(n) << en;
    return 0;
}