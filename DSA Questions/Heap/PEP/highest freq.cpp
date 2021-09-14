#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
string highestFreq(string str)
{
    unordered_map<char, int> mp;
    for (auto val : str)
    {
        mp[val]++;
    }
    string res = "";
    int freq = 0;
    for (auto val : mp)
    {
        if (val.second > freq)
        {
            freq = val.second;
            res = val.first;
        }
    }
    res = res + " " + to_string(freq);
    return res;
}
int main()
{
    FAST;
    string str = "akashsureshghadge";
    cout << highestFreq(str) << en;
    return 0;
}