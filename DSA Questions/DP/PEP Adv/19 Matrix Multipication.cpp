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
int matrix_mult(vi arr, int n)
{
    vii dp(n, vi(n));
    for (int gap = 2; gap < n; gap++)
    {
        int si = 0, ei = gap;
        while (ei < n)
        {
            dp[si][ei] = INT_MAX;
            for (int i = si + 1; i < ei; i++)
            {
                dp[si][ei] = min(dp[si][ei], dp[si][i] + dp[i][ei] + (arr[si] * arr[i] * arr[ei]));
            }
            si++;
            ei++;
        }
    }
    return dp[0][n - 1];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    cout << matrix_mult(vec, N) << en;
    return 0;
}