/*
we have infinite supply of coins and we need to make amount k
so how many ways we can achive this
*/

/*
here we basically
itrating over coins and if is there any way to pay that amount 
i.e if we have 2 1 3 coins and we want to know 3 amount is it payable then we simply 
itrate over 1 2 3 coins 
and for every coin we check after substracting the value from amount is there any option to pay
e.g. for second itration i.e for 2
we ask at amount 3 we have any option to pay amount 1 (3-2) and we have options so we addd it to ans
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
int sol(vi &coins, int k)
{
    int n = coins.size();
    vi dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
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