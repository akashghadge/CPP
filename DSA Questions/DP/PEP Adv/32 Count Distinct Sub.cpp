/*
here basically we have string str
and find only distinct subsequences

if we have 
abc
then 8 (2^4) distinct sub posable
but for 
abcc duplication is here so here due cc
we have only 12 not 16(2^4) 

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
long long count_distinct_subseq(string str)
{
    int n = str.size();
    vll dp(n + 1);
    dp[0] = 1;
    unordered_map<char, int> mp;
    for (int i = 1; i <= n; i++)
    {
        char curr_char = str[i - 1];
        dp[i] = dp[i - 1] * 2;
        
        if (mp.find(curr_char) != mp.end())
        {
            int prev_index = mp[curr_char];
            dp[i] = dp[i] - dp[prev_index - 1];
        }
        mp[curr_char] = i;
    }
    printVector(dp);
    return dp[n] - 1;
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << count_distinct_subseq(str) << en;
    return 0;
}