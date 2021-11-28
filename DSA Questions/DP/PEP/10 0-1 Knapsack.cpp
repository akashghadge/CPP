/*
standard problem

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
    vector<vi> dp(n + 1, vi(capicity + 1));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (j >= weight[i - 1])
            {
                int rem_weight = j - weight[i - 1];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][rem_weight] + price[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capicity];
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