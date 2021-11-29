/*
here we have multiple colors
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
int sol(vector<vi> houses)
{
    vector<vi> dp(houses.size(), vi(houses[0].size()));
    for (int i = 0; i < houses.size(); i++)
    {
        dp[0][i] = houses[0][i];
    }
    for (int i = 1; i < houses.size(); i++)
    {
        for (int j = 0; j < houses[0].size(); j++)
        {
            int min_value = INT_MAX;
            for (int k = 0; k < houses[0].size(); k++)
            {
                if (k != j)
                    min_value = min(min_value, dp[i - 1][k]);
            }

            dp[i][j] = houses[i][j] + min_value;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < houses[0].size(); i++)
    {
        ans = min(ans, dp[dp.size() - 1][i]);
    }
    return ans;
}
int main()
{
    FAST;
    int N, M;
    cin >> N >> M;
    vector<vi> houses(N, vi(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> houses[i][j];
        }
    }
    cout << sol(houses) << en;
    return 0;
}