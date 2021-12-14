/*
here we have two strings
word aabbcc and pattern abc
output :-
give how many ways you can make word to pattern

sample case :- 
input :-
aabbcc abc
here we have 2 a and we need only 1 a so we have two options
here we have 2 b and we need only 1 b so we have two options
here we have 2 c and we need only 1 c so we have two options
therefore output will 6

output :-
6
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
int distinct_tranformation_rec(string word, string pattern, int i_word, int i_pattern)
{
    if (i_word == word.size())
    {
        if (i_pattern < pattern.size())
            return 0;
        else
            return 1;
    }
    else if (i_pattern == pattern.size())
    {
        return 0;
    }
    int ans = 0;
    if (word[i_word] != pattern[i_pattern])
    {
        ans = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern);
    }
    else
    {
        int include = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern);
        int exclude = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern + 1);
        ans = include + exclude;
    }
    return ans;
}
int distinct_tranformation_memo(string word, string pattern, int i_word, int i_pattern, vii &dp)
{
    if (i_word == word.size())
    {
        if (i_pattern < pattern.size())
            return 0;
        else
            return 1;
    }
    else if (i_pattern == pattern.size())
    {
        return 0;
    }

    if (dp[i_word][i_pattern] != -1)
    {
        return dp[i_word][i_pattern];
    }
    int ans = 0;
    if (word[i_word] != pattern[i_pattern])
    {
        ans = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern);
    }
    else
    {
        int include = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern);
        int exclude = distinct_tranformation_rec(word, pattern, i_word + 1, i_pattern + 1);
        ans = include + exclude;
    }
    dp[i_word][i_pattern] = ans;
    return ans;
}
int distinct_tranformation_tabulation(string word, string pattern)
{
    int n = word.size();
    int m = pattern.size();
    vii dp(m + 1, vi(n + 1));
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m)
                dp[i][j] = 1;
            else if (j == n)
                dp[i][j] = 0;
            else
            {
                bool equal = (word[j] == pattern[i]);
                if (equal)
                {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i][j + 1];
                }
                else
                {
                    dp[i][j] = dp[i][j + 1];
                }
            }
        }
    }
    return dp[0][0];
}
int main()
{
    FAST;
    string word, pattern;
    cin >> word >> pattern;
    vii dp(word.size(), vi(pattern.size(), -1));
    cout << distinct_tranformation_rec(word, pattern, 0, 0) << endl;
    cout << distinct_tranformation_memo(word, pattern, 0, 0, dp) << endl;
    cout << distinct_tranformation_tabulation(word, pattern) << endl;
}