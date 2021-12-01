/*
standard
*/

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
    vi left(n);
    vi right(n);
    int least = prices[0];
    for (int i = 1; i < n; i++)
    {
        least = min(least, prices[i]);
        int curr_profit = prices[i] - least;
        left[i] = max(curr_profit, left[i - 1]);
    }
    int max_price = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        max_price = max(max_price, prices[i]);
        int curr_profit = max_price - prices[i];
        right[i] = max(curr_profit, right[i + 1]);
    }

    int final_profit = 0;
    for (int i = 0; i < n; i++)
    {
        final_profit = max(final_profit, left[i] + right[i]);
    }
    return final_profit;
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