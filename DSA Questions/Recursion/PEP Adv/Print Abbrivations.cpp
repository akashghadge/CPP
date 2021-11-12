/*
ab have
ab
a1
1b
2
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
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void helper(string str, int index, string curr, vector<string> &res)
{
    if (index == str.size())
    {
        res.push_back(curr);
        return;
    }
    string temp = curr + str[index];
    helper(str, index + 1, curr + "1", res);
    helper(str, index + 1, temp, res);
}
vector<string> abbrivations(string str)
{
    vector<string> res;
    helper(str, 0, "", res);
    for (auto &curr : res)
    {
        string ans = "";
        int c = 0;
        for (int i = 0; i < curr.size();)
        {
            if (curr[i] == '1')
            {
                c++;
                i++;
            }
            else if (c != 0)
            {
                ans += to_string(c);
                c = 0;
            }
            else
            {
                ans += curr[i];
                i++;
            }
        }
        if (c != 0)
        {
            ans += to_string(c);
        }
        curr = ans;
    }
    return res;
}
void pepCoding(string str, int index, string ans, int c)
{
    if (str.size() == index)
    {
        if (c == 0)
            cout << ans << " ";
        else
            cout << ans + to_string(c) << " ";
        return;
    }
    pepCoding(str, index + 1, ans, c + 1);
    if (c == 0)
        pepCoding(str, index + 1, ans + str[index], c);
    else
        pepCoding(str, index + 1, ans + to_string(c) + str[index], 0);
}

int main() 
{
    FAST;
    string str;
    cin >> str;
    vector<string> res = abbrivations(str);
    printVector(res);
    pepCoding(str, 0, "", 0);
    return 0;
}