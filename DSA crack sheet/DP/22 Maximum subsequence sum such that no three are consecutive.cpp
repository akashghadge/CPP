/*
Given a sequence of positive numbers, find the maximum dp that can be formed which has no three consecutive elements present.
Examples : 

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27

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
int max_no_three_consecutive(vi arr, int n)
{
    vi dp(n, 0);
    if (n >= 1)
        dp[0] = arr[0];

    if (n >= 2)
        dp[1] = arr[0] + arr[1];

    if (n > 2)
        dp[2] = max(dp[1], max(arr[1] +
                                   arr[2],
                               arr[0] + arr[2]));
    for (int i = 3; i < n; i++)
        dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]),
                    arr[i] + arr[i - 1] + dp[i - 3]);
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
    cout << max_no_three_consecutive(arr, N) << en;
    return 0;
}