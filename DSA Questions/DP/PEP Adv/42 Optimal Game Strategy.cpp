/*
we have array of integers

we can collect coins from ends that is first end and last end
condition:-
who collects max coins wins
collect max possible number
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
/*
when things happens to you assume the worst
when you do something do the best
*/
int optimal_strategy(vi arr, int n)
{
    vii dp(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int j = gap, i = 0; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = arr[i];
            }
            else if (gap == 1)
            {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else
            {
                int ans1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int ans2 = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                dp[i][j] = max(ans1, ans2);
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << optimal_strategy(arr, N) << en;
    return 0;
}