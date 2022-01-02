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
bool solution(string a, unordered_map<string, int> s)
{
    int n = a.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            string w2check = a.substr(j, i - j);
            if (dp[j] && s.find(w2check) != s.end())
            {
                dp[i] = true;
                c++;
                //break;
            }
        }
    }

    //cout << c << endl;
    return dp[n] > 0;
}
int main()
{
    FAST;
    int n;
    string str;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        mp[temp]++;
    }
    cin >> str;
    cout << solution(str, mp) << en;

    return 0;
}