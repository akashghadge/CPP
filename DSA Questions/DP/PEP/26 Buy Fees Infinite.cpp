/*
standard
*/
/*
Here we have to make as lows as transictions to avoid fees
for this dp approch is same as exclude and include 

we make two varibles 
1) we have one stock in buying (buying state)
2) we have account settler i.e buy and sell same 
every iterations :-
for buying we check if we sell this stock and again buy is it we make profit 
    formula :-
        buy=max(buy,sell-arr[i]);

for selling we just sell it and 
    formula :-
        sell=max(sell,prev_buy+arr[i]-fees)
*/
/*
12
10 15 17 20 16 18 22 20 22 20 23 25
3
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
int sol(vi prices, int fee)
{
    int n = prices.size();
    int buy = -prices[0];
    int sell = 0;
    for (int i = 1; i < n; i++)
    {
        int prev_buy = buy;
        buy = max(buy, sell - prices[i]);
        sell = max(sell, prev_buy + prices[i] - fee);
    }
    return max(buy, sell);
}
int main()
{
    FAST;
    int N, fee;
    cin >> N;
    vi prices(N);
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }
    cin >> fee;
    cout << sol(prices, fee) << en;
    return 0;
}