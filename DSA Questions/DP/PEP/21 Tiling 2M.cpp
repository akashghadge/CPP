/*
we have floor which have dimenssions of M * n
and tile have dim of M*1
we need to give count of arrangments possible
for 3
we can place vertical all
| | |
we can place horizontal and vertical
= |

| =

here we have 3 ways to place 2*1 tiles into 2*3 floor
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
int sol(int n, int m)
{
    vector<int> dp(n + 1);
    int M = 1e9 + 7;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i < m)
        {
            dp[i] = 1;
        }
        else if (i == m)
        {
            dp[i] = 2;
        }
        else if (i - m >= 0)
        {
            dp[i] = (dp[i - 1] + dp[i - m]) % M;
        }
    }
    return dp[n];
}
int main()
{
    FAST;
    int n, m;
    cin >> n >> m;
    // n = 4;
    // m = 2;
    cout << sol(n, m) << en;
    return 0;
}