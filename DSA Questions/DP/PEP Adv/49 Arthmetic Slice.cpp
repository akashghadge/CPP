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
int arithmetic_slice(vi arr, int n)
{
    vi dp(n);
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (arr[i - 2] - arr[i - 1] == arr[i - 1] - arr[i])
        {
            dp[i] = dp[i - 1] + 1;
            ans += dp[i];
        }
    }
    return ans;
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
    cout << arithmetic_slice(arr, N) << en;
    return 0;
}