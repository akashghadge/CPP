/*
here we have array which indicates prices if we cut n length road in to it
e.g
8
1 5 8 9 10 17 17 20
we need max profit
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
int road_cutting(vi price, int n)
{
    vi dp(n + 1);
    price.insert(price.begin(), 0);

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                max_val = max(max_val, dp[i - j] + price[j]);
        }
        dp[i] = max(price[i], max_val);
    }
    return dp[n];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    cout << road_cutting(vec, N) << en;
    return 0;
}