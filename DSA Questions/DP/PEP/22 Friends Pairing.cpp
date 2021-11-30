/*
we have n friend s
have two choices each friends
either go seprate either pair
n=3
1 2 3
12 3
1 23 
13 2
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
        dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
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