/*
here we have string of parenthesis 
e.g 
(()))()

and we need to print string which balanced and have minimum number of removals
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
int getMinRemove(string str)
{
    stack<char> st;
    for (auto ch : str)
    {
        if (ch == '(')
            st.push(ch);
        else
        {
            if (st.size() == 0)
                st.push(ch);
            else if (st.top() == '(')
                st.pop();
            else
                st.push(ch);
        }
    }
    return st.size();
}
void helper(string str, int min_remove, unordered_map<string, int> &mp)
{
    if (min_remove == 0)
    {
        int isValid = getMinRemove(str);
        if (isValid == 0 && mp.find(str) == mp.end())
        {
            cout << str << en;
            mp[str]++;
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        helper(left + right, min_remove - 1, mp);
    }
}
void sol(string str)
{
    int min_remove = getMinRemove(str);
    unordered_map<string, int> mp;
    helper(str, min_remove, mp);
}
int main()
{
    FAST;
    string str;
    cin >> str;
    sol(str);
    return 0;
}