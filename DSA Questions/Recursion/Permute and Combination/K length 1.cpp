/*
it is given n and str
str can containes repetation
make distrinct charecter words having k length this is quite similar like work selection but here we want to arange as well
selection + arrangement
here we follow approch of box selection i.e box at level and box have choices to select which box would be like to place an item
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
void helper(int curr, int total, vector<bool> &used, string str, string ans)
{
    if (curr >= total)
    {
        cout << ans << en;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (used[i] == false)
        {
            used[i] = true;
            helper(curr + 1, total, used, str, ans + str[i]);
            used[i] = false;
        }
    }
}
void sol(string str, int k)
{
    unordered_map<char, int> mp;
    for (auto ch : str)
    {
        mp[ch]++;
    }
    string ns = "";
    for (auto val : mp)
    {
        ns.push_back(val.first);
    }
    vector<bool> used(ns.size(), false);
    helper(0, k, used, ns, "");
}
int main()
{
    FAST;
    int k;
    string str;
    cin >> str >> k;
    sol(str, k);
    return 0;
}