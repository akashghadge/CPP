/*
this is further modification on wildcart
same we have word and pattern
but
. must match any charecter
* team up with preceding charecter i.e s* or .* and then match zero chars, one s, two ss ,three sss as simillar .,..,...
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
bool regular_exp(string word, string pat)
{
    int n = word.size();
    int m = pat.size();
    vii dp(m + 1, vi(n + 1));
    dp[0][0] = true;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (j == 0)
            {
                if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 2][j];
            }
            else
            {
                if (pat[i - 1] == '.' || pat[i - 1] == word[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if (pat[i - 2] == word[j - 1] || pat[i - 2] == '.')
                        dp[i][j] = dp[i][j - 1] || dp[i - 2][j];
                }
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}
int main()
{
    FAST;
    string pat, word;
    cin >> pat >> word;
    regular_exp(word, pat) ? cout << "true" : cout << "false";
    cout << en;
    return 0;
}