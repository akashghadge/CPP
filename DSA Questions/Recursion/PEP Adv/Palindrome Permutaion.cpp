/*
given one string 
print it's only palindromin partitions

ans
here we making permutation of half charecters and then reverse it and attach it and if any odd present max 1 odd then we attach it to middle

permute(str/2) + odd + rev(permute(str/2))
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
void permute_palindrome(int curr, int len, unordered_map<char, int> &mp, char odd, string ans)
{
    if (curr >= len)
    {
        string rev = ans;
        reverse(rev.begin(), rev.end());
        odd != ' ' ? cout << ans + odd + rev << en
                   : cout << ans + rev << en;
        return;
    }
    for (auto &p : mp)
    {
        if (p.second > 0)
        {
            p.second--;
            permute_palindrome(curr + 1, len, mp, odd, ans + p.first);
            p.second++;
        }
    }
}
int main()
{
    FAST;
    string str;
    cin >> str;
    unordered_map<char, int> mp;
    // basically if odds are greater than 1 then we could to this
    char odd = ' ';
    int oddsCount = 0;
    int length = 0;
    for (auto ch : str)
    {
        mp[ch]++;
    }

    for (auto &p : mp)
    {
        if (p.second % 2 == 0)
        {
            p.second /= 2;
        }
        else
        {
            odd = p.first;
            p.second /= 2;
            oddsCount++;
        }
        length += (p.second);
    }

    if (oddsCount > 1)
    {
        cout << "-1" << en;
        return 0;
    }
    permute_palindrome(0, length, mp, odd, "");
}