/*
here we have 3 houses
and we want to print those houses
consecative house should not print in same color

test
4
1 5 7
5 8 4
3 2 9
1 2 4

each value show cost of paint
i.e 
for first house 
red blue green
1    5     7


4
1 5 7
5 8 4
3 2 9
1 2 4
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
    vector<vi> dp(houses.size(), vi(3));
    dp[0][0] = houses[0][0];
    dp[0][1] = houses[0][1];
    dp[0][2] = houses[0][2];
    for (int i = 1; i < houses.size(); i++)
    {
        dp[i][0] = houses[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = houses[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = houses[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int n = dp.size() - 1;
    int temp = min(dp[n][0], dp[n][1]);
    return min(temp, dp[n][2]);
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<vi> houses(N, vi(3));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> houses[i][j];
        }
    }
    cout << sol(houses) << en;
    return 0;
}