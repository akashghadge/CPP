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
        cout << en;
    }
    cout << endl;
}
int string_identical(string str1, string str2, int x, int y)
{
    int n = str1.size();
    int m = str2.size();
    vii dp(n + 1, vi(m + 1));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n and j == m)
                dp[i][j] = 0;
            else if (i == n)
                dp[i][j] = dp[i][j + 1] + y;
            else if (j == m)
                dp[i][j] = dp[i + 1][j] + x;
            else
            {
                char ch_1 = str1[i];
                char ch_2 = str2[j];
                if (ch_1 == ch_2)
                    dp[i][j] = dp[i + 1][j + 1];
                else
                {
                    dp[i][j] = min(dp[i][j + 1] + y, dp[i + 1][j] + x);
                }
            }
        }
    }
    return dp[0][0];
}
// here we need to just cancel out the charecter of lca cause lca is longest common sub
// if max part is same so we deleting the min chars
int string_indetical_pep(string str1, string str2, int x, int y)
{
    int n = str1.size();
    int m = str2.size();
    vii dp(n + 1, vi(m + 1));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n and j == m)
                dp[i][j] = 0;
            else if (i == n)
                dp[i][j] = 0;
            else if (j == m)
                dp[i][j] = 0;
            else
            {
                char ch_1 = str1[i];
                char ch_2 = str2[j];
                if (ch_1 == ch_2)
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
    }
    int lca = dp[0][0];
    int ans = (n - lca) * x + (m - lca) * y;
    return ans;
}

int main()
{
    FAST;
    string str1, str2;
    cin >> str1 >> str2;
    int x, y;
    cin >> x >> y;
    cout << string_identical(str1, str2, x, y) << en;
    cout << string_indetical_pep(str1, str2, x, y) << en;
    return 0;
}