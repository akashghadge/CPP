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

/*
standard dp problem
so here the tabulation is used
dp[transaction][day] is derived from the either 
i.e form dp[transactions][day-1] 

or we can drived from
max of all k-1 transactions completed before that day 
i.e from the all dp[transactions-1][day-1], dp[trasactions-1][day-2]...dp[transactions-1][0]
note :- for optimising this loop we will get track of max_profit_one_less value

*/
int sol(vi prices, int k)
{
    int n = prices.size();
    if (n == 1)
        return 0;
    vii dp(n, vi(k + 1));
    for (int transaction = 1; transaction < k; transaction++)
    {
        int max_profit_one_less = INT_MIN;
        for (int day = 1; day < n; day++)
        {
            max_profit_one_less = max(max_profit_one_less, dp[transaction - 1][day - 1] - prices[day - 1]);
            dp[transaction][day] = max(dp[transaction][day - 1], max_profit_one_less + prices[day]);
        }
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi prices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }
    int k;
    cin >> k;
    cout << sol(prices, k) << en;
    return 0;
}