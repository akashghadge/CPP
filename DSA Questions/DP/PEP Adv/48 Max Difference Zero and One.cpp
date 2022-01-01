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
int diff_zeros(string str)
{
    int n = str.size();
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        if (str[i] == '0')
        {
            val = 1;
        }
        else
        {
            val = -1;
        }
        if (curr < 0)
            curr = val;
        else
            curr += val;
        ans = max(ans, curr);
    }
    if (ans == 0)
        return -1;
    return ans;
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << diff_zeros(str) << en;
    return 0;
}