/*
here we have the pairs of parenthesis so and we need to give numbers of combinations possible which are valid
*/
/*
here we solve it through catalan by making it decision of either we place pair in parenthesis or outside of the parenthesis
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
    if (n == 0)
        return 0;
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
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << vallay_mountain(n) << en;
}