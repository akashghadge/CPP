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
int convert_string(string str, string req)
{
    int n = str.size();
    int m = req.size();
    vii dp(m + 1, vi(n + 1, 0));
    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == m)
            {
                dp[i][j] = 1;
            }
            else if (j == n)
            {
                dp[i][j] = 0;
            }
            else
            {
                char ch_str = str[j];
                char ch_req = req[i];
                if (ch_str != ch_req)
                {
                    dp[i][j] = dp[i][j + 1];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i][j + 1];
                }
            }
        }
    }
    printVector(dp);
    return dp[0][0];
}
int main()
{
    FAST;
    string str, req;
    cin >> str >> req;
    cout << convert_string(str, req) << en;
    return 0;
}