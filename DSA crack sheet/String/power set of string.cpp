#include <iostream>
using namespace std;
#include "algorithm"
#include "string"
#include "vector"
int main()
{
}
string util(string s, string current, int i, vector<string> &ans)
{
    if (i >= s.size())
    {
        if (current != "")
            ans.push_back(current);
        return "";
    }
    util(s, current, i + 1, ans);
    util(s, current + s[i], i + 1, ans);
    return "";
}
vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    string current = "";
    util(s, current, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}