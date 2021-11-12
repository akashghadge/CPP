/*
it is given n and str
str can containes repetation
make distrinct charecter words having k length this is quite similar like work selection but here we want to arange as well
selection + arrangement
here we follow approch of item have option to which box it should go i.e 
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
void helper(vector<char> slots, int currSelections, int curr, int totalChars, string str)
{
    if (curr >= totalChars)
    {
        if (currSelections == slots.size())
        {
            for (auto ch : slots)
            {
                cout << ch;
            }
            cout << en;
        }
        return;
    }
    char curr_char = str[curr];
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i] == '_')
        {
            slots[i] = curr_char;
            helper(slots, currSelections + 1, curr + 1, totalChars, str);
            slots[i] = '_';
        }
    }
    helper(slots, currSelections, curr + 1, totalChars, str);
}
void sol(string str, int k)
{
    unordered_map<char, int> mp;
    string ns = "";
    for (auto ch : str)
        mp[ch]++;
    for (auto val : mp)
        ns.push_back(val.first);
    vector<char> slots(k, '_');
    helper(slots, 0, 0, ns.size(), ns);
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