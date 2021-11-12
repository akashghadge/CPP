/*
here we have word which can contain repetation
select distinct charecters but do not do arrange ment on it
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
void helper(int curr, int total, string str, string ans)
{
    if (curr >= str.size())
    {
        if (ans.size() == total)
        {
            cout << ans << en;
        }
        return;
    }
    helper(curr + 1, total, str, ans);
    helper(curr + 1, total, str, ans + str[curr]);
}
int sol(string str, int n)
{
    unordered_map<char, int> freq;
    for (auto ch : str)
        freq[ch]++;

    string ns = "";
    for (auto val : freq)
    {
        ns.push_back(val.first);
    }
    helper(0, n, ns, "");
}
int main()
{
    FAST;
    string str;
    int n;
    cin >> str >> n;
    sol(str, n);
    return 0;
}