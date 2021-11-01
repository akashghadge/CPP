/*

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
        cout << vec[i] << en;
    }
}
void helper(string str, vector<string> &res, int i, string curr)
{
    if (i == str.size())
    {
        res.push_back(curr);
        return;
    }
    helper(str, res, i + 1, curr);
    helper(str, res, i + 1, curr + str[i]);
}
void subsequences(string str, vector<string> &res)
{
    helper(str, res, 0, "");
}
int main()
{
    string str;
    // cin >> str;
    vector<string> res;
    subsequences("abc", res);
    printVector(res);
    return 0;
}