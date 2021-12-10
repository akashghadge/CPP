/*
here catlan numbers is 
c1 1
c2 1
c3 c1c2  c2c1 => 1*1 + 1*1 => 2
c4 c3c1  c2c2 c1c3 => 2*1 + 1*1 + 1*2 => 5
c5 c4c3 ...
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
int catlan(int n)
{
    vi dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        int curr_catlan = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            curr_catlan += dp[j] * dp[i - j];
        }
        dp[i] = curr_catlan;
    }
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << catlan(n) << en;
    return 0;
}