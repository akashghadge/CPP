/*
here we have word which can contain repetation
select distinct charecters but do not do arrange ment on it
here same as first but we need to follow approch of second i.e. box have choice to select charecters
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
void print(vector<char> arr)
{
    for (auto ch : arr)
    {
        cout << ch;
    }
    cout << en;
}
void helper(int curr, int total, string str, string ans, int last)
{
    if (curr >= total)
    {
        cout << ans << en;
        return;
    }
    for (int i = last + 1; i < str.size(); i++)
    {
        helper(curr + 1, total, str, ans + str[i], i);
    }
}
int sol(string str, int n)
{
    map<char, int> freq;
    for (auto ch : str)
        freq[ch]++;

    string ns = "";
    for (auto val : freq)
    {
        ns.push_back(val.first);
    }
    cout << ns << en;
    helper(0, n, ns, "", -1);
}
int main()
{
    FAST;
    string str;
    int n;
    cin >> str >> n;
    sol(str, n);
    return 0;
}