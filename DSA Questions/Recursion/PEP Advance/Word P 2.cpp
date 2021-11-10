/*
here question is quite same as word p 1 but difference is here we have to do it by permutation 1 approch i.e
charecter have choice to decied its place 
so tricky part is avoiding duplicate computation so for this we just add charecter upfront if charecter place earilier then do not add
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
void print(vector<char> place)
{
    for (auto ch : place)
    {
        cout << ch;
    }
    cout << en;
}
void sol(int curr, int total, string str, vector<char> place, unordered_map<char, int> mp)
{
    if (curr == total)
    {
        print(place);
        return;
    }
    int last_apperence = mp[str[curr]];
    for (int i = last_apperence + 1; i < str.size(); i++)
    {
        if (place[i] == '_')
        {
            place[i] = str[curr];
            mp[str[curr]] = i;
            sol(curr + 1, total, str, place, mp);
            mp[str[curr]] = '_';
            place[i] = '_';
        }
    }
}
int main()
{
    FAST;
    string str;
    cin >> str;
    vector<char> place(str.size(), '_');
    unordered_map<char, int> mp;
    for (auto ch : str)
        mp[ch] = -1;

    sol(0, str.size(), str, place, mp);
    return 0;
}