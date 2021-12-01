/*
here we need to follow cool down of 1 day after selling
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
int sol(vi prices)
{
    int n = prices.size();
    int buy = -prices[0];
    int sell = 0;
    int cool = 0;
    for (int i = 1; i < n; i++)
    {
        int prev_buy = buy;
        int prev_sell = sell;
        buy = max(buy, cool - prices[i]);
        sell = max(sell, prev_buy + prices[i]);
        cool = max(cool, prev_sell);
    }
    return sell;
}
int main()
{
    FAST;
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