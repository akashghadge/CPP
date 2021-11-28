/*
Here we need to find count of permutations of coins which is used to make amount k
note we have infinte supply of coins
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

// test
// n=3
// 2 3 5
// k=7
int sol(vi &coins, int k)
{
    int n = coins.size();
    vi dp(k + 1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        int options = 0;
        for (int j = 0; j < n; j++)
        {
            int coin = coins[j];
            if (coin <= i)
            {
                options += dp[i - coin];
            }
        }
        dp[i] = options;
    }
    return dp[k];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    int k;
    cin >> k;
    cout << sol(coins, k) << en;
    return 0;
}