/*
Given a string S, the task is to remove all the duplicates in the given string. 
Below are the different methods to remove duplicates in a string.
*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
// either you go from begin to have delete all right duplicate elements
// or backward for begins repeted elelemetn
string rm_dup(string &str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size();)
    {
        if (mp.find(str[i]) != mp.end())
        {
            str.erase(str.begin() + i);
        }
        else
        {
            mp[str[i]]++;
            i++;
        }
    }
    return str;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << rm_dup(s) << en;
    return 0;
}