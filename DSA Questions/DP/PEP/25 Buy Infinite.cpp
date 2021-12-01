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
int sol(vi prices)
{
    int buy_date = 0;
    int sell_date = 0;
    int overall_profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] >= prices[i - 1])
        {
            sell_date++;
        }
        else
        {
            overall_profit += prices[sell_date] - prices[buy_date];
            buy_date = sell_date = i;
        }
    }
    overall_profit += prices[sell_date] - prices[buy_date];
    return overall_profit;
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
    cout << sol(prices) << en;
    return 0;
}