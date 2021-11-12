/*
here we need to find permutaion of string which can consists duplicate chars aswell
aabb
so we need to use map to make decisions so we don't solve same problem again and again
and pep condition is use permutation type 2 i.e we need to make choices which letters should box get on level
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
void helper(int curr, unordered_map<char, int> freq, string str, string ans)
{
    if (curr == str.size())
    {
        cout << ans << en;
        return;
    }
    for (auto &p : freq)
    {
        if (p.second > 0)
        {
            p.second--;
            helper(curr + 1, freq, str, ans + p.first);
            p.second++;
        }
    }
}
void sol(string str)
{
    unordered_map<char, int> freq;
    for (auto ch : str)
        freq[ch]++;
    helper(0, freq, str, "");
}
int main()
{
    FAST;
    string str;
    cin >> str;
    sol(str);
    return 0;
}