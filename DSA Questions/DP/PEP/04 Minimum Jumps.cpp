// find minimum jumps
/*
10
1 1 1 4 9 8 1 1 10 1

10
3 2 4 2 0 2 3 1 2 2
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
int sol(int n, vector<int> &jumps)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (jumps[i] <= 0)
            continue;

        int min_value = INT_MAX;
        for (int j = 1; j <= jumps[i] && j + i < dp.size(); j++)
        {
            min_value = min(min_value, dp[i + j]);
        }
        if (min_value != INT_MAX)
            dp[i] = min_value + 1;
    }
    return dp[0];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    cout << sol(n, jumps) << en;
    return 0;
}