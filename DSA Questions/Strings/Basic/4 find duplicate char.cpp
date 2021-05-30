#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int n = str.size();
    // o(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] == str[j])
            {
                cout << str[i] << " ";
            }
        }
    }
    cout << en;
    // o(n) with space o(n)
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
    }

    for (auto val : mp)
    {
        if (val.second >= 2)
        {
            cout << val.first << " ";
        }
    }
    cout << en;
    return 0;
}