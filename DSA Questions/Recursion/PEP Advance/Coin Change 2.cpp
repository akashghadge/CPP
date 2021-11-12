/*
Print all possible combination ;) of coins which can be used to pay pill amount of k
you have infinte coin of each value
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
void sol(int i, vector<int> coins, int curr_sum, int amount, string ans)
{
    if (i == coins.size())
    {
        if (curr_sum == amount)
            cout << ans << en;
        return;
    }
    for (int j = amount / coins[i]; j >= 1; j--)
    {
        string part = "";
        for (int k = 0; k < j; k++)
        {
            part += to_string(coins[i]) + "-";
        }
        sol(i + 1, coins, curr_sum + coins[i] * j, amount, ans + part);
    }
    sol(i + 1, coins, curr_sum, amount, ans);
}
int main()
{
    FAST;
    int n, k;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cin >> k;
    sol(0, coins, 0, k, "");
    return 0;
}