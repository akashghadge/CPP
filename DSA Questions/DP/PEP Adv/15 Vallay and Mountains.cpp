/*
here we have the pairs of up stroke and the down stroke so and we need to make vallay and mountains
*/
/*
here we solve it through catalan by making it decision of either we place pair in par or outside of the pair
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
int vallay_mountain(int n)
{
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 0;
        int r = i - 1;
        while (l < i)
        {
            dp[i] += (dp[l] * dp[r]);
            l++;
            r--;
        }
    }
    for (auto val : dp)
    {
        cout << val << " ";
    }
    cout << en;

    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << vallay_mountain(n) << en;
}