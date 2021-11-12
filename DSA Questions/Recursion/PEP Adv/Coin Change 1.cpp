/*
Print all possible combination ;) of coins which can be used to pay pill amount of k
you have only 1 coin of each value
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
void sol(vector<int> coins, int k, int ptr, int curr_sum, string ans)
{
    if (ptr >= coins.size())
    {
        if (curr_sum == k)
        {
            cout << ans << en;
        }
        return;
    }
    sol(coins, k, ptr + 1, curr_sum, ans);
    sol(coins, k, ptr + 1, curr_sum + coins[ptr], ans + to_string(coins[ptr]) + "-");
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
    sol(coins, k, 0, 0, "");
    return 0;
}