/*
20
5
6 7 12 14 15
5 8 5 3 1
5
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
int highway_billboard(vi pos, vi revenue, int len, int n, int k)
{
    int ans = 0;
    vi dp(len, 0);
    dp[0] = revenue[0];
    for (int i = 1; i < len; i++)
    {
        int max_ans = 0;
        for (int j = 0; j < i; j++)
        {
            int dist = pos[i] - pos[j];
            if (dist > k)
            {
                max_ans = max(max_ans, dp[j]);
            }
        }
        dp[i] = max_ans + revenue[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int highway_billboard_op(vi pos, vi revenue, int len, int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++)
    {
        mp[pos[i]] = revenue[i];
    }
    vi dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            dp[i] = dp[i - 1];
            continue;
        }
        int prev_rev = dp[i - 1];
        int curr_rev = mp[i];
        if (i - k - 1 >= 0)
        {
            curr_rev += dp[i - k - 1];
        }
        dp[i] = max(prev_rev, curr_rev);
    }
    return dp[n];
}

int main()
{
    FAST;
    int n, len, k;
    cin >> n >> len;
    vi pos(len);
    vi revenue(len);
    for (int i = 0; i < len; i++)
    {
        cin >> pos[i];
    }

    for (int i = 0; i < len; i++)
    {
        cin >> revenue[i];
    }
    cin >> k;
    cout << highway_billboard(pos, revenue, len, n, k) << en;
    cout << highway_billboard_op(pos, revenue, len, n, k) << en;
    return 0;
}