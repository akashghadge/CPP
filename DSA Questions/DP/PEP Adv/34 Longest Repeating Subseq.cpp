/*
we need to find longest repeating subsequence such sub seq does not share 
same index charecter
means
abcabc
here 
abc is longest repeating sub seq okay 
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
int longest_repeating_subseq(string str)
{
    int n = str.size();
    vii dp(n + 1, vi(n + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (str[i] == str[j] && i != j)
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    printVector(dp);
    return dp[0][0];
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << longest_repeating_subseq(str) << en;
    return 0;
}