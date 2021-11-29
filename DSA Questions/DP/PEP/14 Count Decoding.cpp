/*
here we have strign num
e.g. 123
and we have to give count of decodings possible
a => 1
b => 2
....

for 123
we have 3 endcodings
i.e abc lc aw
*/

/*
here we have special cases like 
00
01
10
11
1 is any digit

so for 00 no encoding possible
dp[i]=0
for 01 
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(string num)
{
    vi dp(num.size());
    dp[0] = 1;
    for (int i = 1; i < num.size(); i++)
    {
        if (num[i - 1] == '0' && num[i] == '0')
        {
            dp[i] = 0;
        }
        else if (num[i - 1] == '0' && num[i] != '0')
        {
            dp[i] = dp[i - 1];
        }
        else if (num[i - 1] != '0' && num[i] == '0')
        {
            if (num[i - 1] == '1' || num[i - 1] == '2')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = 0;
            }
        }
        else
        {
            int comp_num = (num[i - 1] - '0') * 10 + num[i] - '0';
            if (comp_num <= 26)
            {
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[num.size() - 1];
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << sol(str) << en;
    return 0;
}