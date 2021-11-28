/*
knapsack but here we can use infinte supply of items
test case
5
15 14 10 45 30
2 5 1 3 4
7
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
int sol(vi price, vi weight, int n, int capicity)
{
    vi dp(capicity + 1);
    for (int i = 0; i <= capicity; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int curr_weight = weight[j];
            if (i >= curr_weight)
            {
                dp[i] = max(dp[i], dp[i - curr_weight] + price[j]);
            }
        }
    }

    return dp[capicity];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi price(N);
    vi weight(N);
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    int capicity;
    cin >> capicity;
    cout << sol(price, weight, N, capicity) << en;
    return 0;
}