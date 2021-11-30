/*
we have floor which have dimenssions of 2 * n
and tile have dim of 2*1
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
int sol(int n)
{
    vi dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << sol(n) << en;
    return 0;
}