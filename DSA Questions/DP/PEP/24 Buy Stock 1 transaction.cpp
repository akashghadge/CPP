/*
stadnard questions
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
    int lowest_price = INT_MAX;
    int curr_profit = 0;
    int overall_profit = 0;
    for (int price : prices)
    {
        lowest_price = min(lowest_price, price);
        curr_profit = price - lowest_price;
        overall_profit = max(overall_profit, curr_profit);
    }
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