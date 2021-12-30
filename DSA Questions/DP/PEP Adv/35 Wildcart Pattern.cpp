/*
word and pattenr
pattern can include 
? means must consume any one chars 
* means can consume zeros one two ... chars
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
bool match(string word, string pat)
{
    int n = word.size();
    int m = pat.size();
    vii dp(m + 1, vi(n + 1));
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m && j == n)
                dp[i][j] = true;
            else if (i == m)
                dp[i][j] = false;
            else if (j == n)
                dp[i][j] = false;
            else
            {
                char ch_pat = pat[i];
                char ch_word = word[j];
                if (ch_pat == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (ch_pat == '*')
                {
                    // we can optimise this loop
                    dp[i][j] = dp[i + 1][j];
                    for (int ptr = 1; ptr <= n; ptr++)
                    {
                        dp[i][j] = dp[i][j] or dp[i + 1][j + ptr];
                    }
                }
                else if (ch_pat == ch_word)
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    return dp[0][0];
}

bool matchOptimise(string word, string pat)
{
    int n = word.size();
    int m = pat.size();
    vii dp(m + 1, vi(n + 1));
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m && j == n)
                dp[i][j] = true;
            else if (i == m)
                dp[i][j] = false;
            else if (j == n)
                dp[i][j] = false;
            else
            {
                char ch_pat = pat[i];
                char ch_word = word[j];
                if (ch_pat == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (ch_pat == '*')
                {
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                }
                else if (ch_pat == ch_word)
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    return dp[0][0];
}
int main()
{
    FAST;
    string pat, word;
    cin >> pat >> word;
    cout << match(word, pat) << en;
    cout << matchOptimise(word, pat) << en;
    return 0;
}