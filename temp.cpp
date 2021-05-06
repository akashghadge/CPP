#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    int n;
    cin >> n;
    string str[n];
    int i = 0;
    while (i < n)
    {
        cin >> str[i];
        i++;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            mp[str[i][j]]++;
        }
    }
    for (auto val : mp)
    {
        cout << val.first << " is " << val.second << " times" << endl;
    }
}