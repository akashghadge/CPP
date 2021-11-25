// same as previous but give count only
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int totalCounts = 0;
int totalCountsDP1 = 0;
int pathCount(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    totalCounts++;
    int p1 = pathCount(num - 1);
    int p2 = pathCount(num - 2);
    int p3 = pathCount(num - 3);
    return p1 + p2 + p3;
}

int pathCountDP1(int num, vector<int> &dp)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    totalCountsDP1++;
    if (dp[num] != 0)
        return dp[num];
    int p1 = pathCountDP1(num - 1, dp);
    int p2 = pathCountDP1(num - 2, dp);
    int p3 = pathCountDP1(num - 3, dp);

    dp[num] = p1 + p2 + p3;
    return dp[num];
}

int pathCountDPWithNoSpace(int num)
{
    vector<int> dp(num + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        if (i == 1)
            dp[i] = dp[i - 1];
        else if (i == 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[num];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << pathCount(n) << " " << totalCounts << en;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    cout << pathCountDP1(n, dp) << " " << totalCountsDP1 << en;
    cout << pathCountDPWithNoSpace(n) << " " << n << en;
    return 0;
}