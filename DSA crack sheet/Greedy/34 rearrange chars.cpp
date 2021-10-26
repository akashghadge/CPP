/*

*/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define en "\n"
class comp
{
    bool operator()(pair<char, int> p1, pair<char, int> p2)
    {
        return p1.second < p2.second;
    }
};
string Arrange(string str)
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size(); i++)
    {
        mp[str[i]]++;
    }
    for (auto p : mp)
    {
        pq.push({p.first, p.second});
    }
    string res = "";
    while (!pq.empty())
    {
        pair<char, int> p = pq.top();
        pq.pop();
        res += p.first;
        p.second--;
        if (p.second != 0)
        {
            pq.push(p);
        }
    }
    return res;
}
bool isAdjusantSame(string str)
{
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
        {
            return false;
        }
    }
    return true;
}
bool isRearr(string str)
{
    string res = Arrange(str);
    return isAdjusantSame(res);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string str;
    while (T--)
    {
        cin >> str;
        cout << isRearr(str) << en;
    }

    return 0;
}