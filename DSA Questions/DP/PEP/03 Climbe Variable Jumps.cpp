/*
we have n stairs 
and each stair have varible jumps so we need to find all possible paths

n=3
jumps={1,2,3};
find count of paths
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int sol(int n, vector<int> &jumps)
{
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= jumps[i] && j + i < dp.size(); j++)
        {
            dp[i] += dp[i + j];
        }
    }
    return dp[0];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    cout << sol(n, jumps) << en;
    return 0;
}