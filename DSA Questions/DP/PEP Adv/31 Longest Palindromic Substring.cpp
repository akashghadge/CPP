/*
longest substring find
aabbcc

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
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int longest_palindrom_substring(string str)
{
    int n = str.size();
    vii dp(n, vi(n, 0));
    int ans = INT_MIN;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = 2;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    printVector(dp);
    return ans;
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << longest_palindrom_substring(str) << en;
    return 0;
}