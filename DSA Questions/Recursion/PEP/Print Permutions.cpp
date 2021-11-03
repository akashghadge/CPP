#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void helper(string curr, string ans, vector<string> &res)
{
    if (curr.size() == 0)
    {
        res.push_back(ans);
        return;
    }
    for (int i = 0; i < curr.size(); i++)
    {
        char ch = curr[i];
        string startPart = curr.substr(0, i);
        string endPart = curr.substr(i + 1);
        string temp = startPart + endPart;
        helper(temp, ans + ch, res);
    }
}
vector<string> sol(string str)
{
    vector<string> res;
    helper(str, "", res);
    return res;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    FAST;
    string str;
    // cin >> str;
    vector<string> res = sol("abc");
    printVector(res);
    return 0;
}