/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..


Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)


Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800


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
int Mod = 1e9 + 7;
int util(int n, int r, vector<vector<int>> &dp)
{
    if (n == 0 && r == 0)
        return 0;
    else if (n < r)
        return 0;
    else if (r == 0)
    {
        dp[n][r] = 1;
        return 1;
    }
    else if (n == r)
    {
        dp[n][r] = 1;
        return dp[n][r];
    }
    if (dp[n][r] != 0)
        return dp[n][r];
    int part1 = util(n - 1, r - 1, dp);
    int part2 = util(n - 1, r, dp);
    int res = ((part1 % Mod) + (part2 % Mod)) % Mod;
    dp[n][r] = res;
    return res;
}
int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1));
    dp[0][0] = 0;
    return util(n, r, dp);
}
int main()
{
    FAST;
    int n, r;
    return 0;
}