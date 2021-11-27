/*
here we have array of nums 
and k (sum)
we need to give ans of is we can have any subset which have sum equals to k
i.e either yes or no

5
4
2
7
1
3
10
output 
true
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
bool sol(vi &arr, int k)
{
    int n = arr.size();
    vector<vi> dp(n + 1, vi(k + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else
            {
                // cause we are asuming empty case as well therefor we i-1
                int val = arr[i - 1];
                if (dp[i - 1][j])
                    dp[i][j] = true;
                else if (j >= val && dp[i - 1][j - val])
                    dp[i][j] = true;
            }
        }
    }
    return dp[n][k];
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
    int K;
    cin >> K;
    sol(arr, K) ? cout << "true" << en : cout << "false" << en;
    return 0;
}