/*

*/
#include <bits/stdc++.h>
using namespace std;
string printSequence(string str)
{
    // code here.
    unordered_map<char, string> mp;
    int curr = 2;
    int count = 1;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (i == 'D' or i == 'G' or i == 'J' or i == 'M' or i == 'P' or i == 'T' or i == 'W')
            curr++, count = 1;
        string str(count, '0' + curr);
        mp[i] = str;
        count++;
    }
    mp[' '] = '0';
    string ans = "";
    for (auto val : str)
        ans += mp[val];
    return ans;
}
int main()
{
}