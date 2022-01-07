/*
Count all subsequences having product less than K
Difficulty Level : Medium
Last Updated : 17 Aug, 2021
Given a positive array, find the number of subsequences having product smaller than K.
Examples: 
 

Input : [1, 2, 3, 4] 
        k = 10
Output :11 
The subsequences are {1}, {2}, {3}, {4}, 
{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, 
{1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2] 
         k = 50
Output : 9

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
int maxproduct_subseq(vi arr, int n, int k)
{
    vii dp(k + 1, vi(n + 1));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];

            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i)

                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
        }
    }
    return dp[k][n];
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
    int k;
    cin >> k;
    cout << maxproduct_subseq(arr, N, k) << en;
    return 0;
}