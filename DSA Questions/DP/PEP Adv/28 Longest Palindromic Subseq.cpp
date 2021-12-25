/*
here we have the string str find longest palindroming subsequence size

aabbcc
6
*/
/*
here we have two strings 
a and b
find the longest common subsequence between them
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
int longest_palindrome_sub(string str)
{
    int n = str.size();
    vii dp(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << longest_palindrome_sub(str) << en;
    return 0;
}