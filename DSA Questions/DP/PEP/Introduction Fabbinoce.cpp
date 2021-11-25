#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int c = 0;
int dc = 0;
int sol(int n)
{
    if (n == 0 || n == 1)
        return n;
    c++;
    int fb1 = sol(n - 1);
    int fb2 = sol(n - 2);
    return fb1 + fb2;
}
int solDP(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != 0)
        return dp[n];
    dc++;
    int fb1 = solDP(n - 1, dp);
    int fb2 = solDP(n - 2, dp);
    dp[n] = fb1 + fb2;
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << sol(n) << " " << c << en;
    vector<int> dp(n + 1, 0);
    cout << solDP(n, dp) << " " << dc << en;
    return 0;
}