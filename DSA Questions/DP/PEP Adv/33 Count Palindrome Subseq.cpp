/*

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
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int count_palindrome_subseq(string str)
{
    int n = str.size();
    vi prev(n);
    vi next(n);
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        prev[i] = mp.find(ch) != mp.end() ? mp[ch] : -1;
        mp[ch] = i;
    }
    mp.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = str[i];
        next[i] = mp.find(ch) != mp.end() ? mp[ch] : -1;
        mp[ch] = i;
    }
    vii dp(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int j = gap, i = 0; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1)
                dp[i][j] = 2;
            else
            {
                char first_ch = str[i];
                char second_ch = str[j];
                if (first_ch != second_ch)
                {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                else
                {
                    int next_occ = next[i];
                    int prev_occ = prev[j];
                    // only one char
                    if (next_occ == prev_occ)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    }
                    // no char
                    else if (next_occ > prev_occ)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    }
                    // more than one
                    else
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[next_occ + 1][prev_occ - 1];
                    }
                }
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
    cout << count_palindrome_subseq(str) << en;
    return 0;
}