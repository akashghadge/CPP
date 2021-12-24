/*
longest common substring
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
int longest_common_substring(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vii dp(n + 1, vi(m + 1));
    int longest_substring = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            char first_char = str1[i];
            char second_char = str2[j];
            if (first_char == second_char)
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            longest_substring = max(longest_substring, dp[i][j]);
        }
    }
    return longest_substring;
}
int main()
{
    FAST;
    string str1, str2;
    cin >> str1 >> str2;
    cout << longest_common_substring(str1, str2) << en;
    return 0;
}