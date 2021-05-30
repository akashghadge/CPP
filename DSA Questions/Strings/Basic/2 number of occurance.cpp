#include <bits/stdc++.h>
using namespace std;
#define en "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]]++;
    }
    for (auto val : mp)
    {
        cout << val.first << " have :" << val.second << en;
    }

    return 0;
}
