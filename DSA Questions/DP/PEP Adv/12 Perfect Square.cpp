/*
here we have n 
and we need to descripe the n by squares of numbers such that we use minimum numbers

e.g 
9 => 1 [3]
7 => 4 [1 1 1 2]
11 => 3 [1 1 3]
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
int perfect_square(int n)
{
    vi dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int min_numbers = INT_MAX;
        for (int j = 1; j <= i; j++)
        {
            int curr_sq = pow(j, 2);
            if (i < curr_sq)
                break;
            min_numbers = min(min_numbers, dp[i - curr_sq]);
        }
        dp[i] = min_numbers + 1;
    }
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << perfect_square(n) << en;
    return 0;
}