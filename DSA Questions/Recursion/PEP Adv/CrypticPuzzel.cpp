/*
here we have 3 words and we need to map all charecters of words such that 

word 1 + word 2 = word 3
note :-
no charecters is maped to more than 1 number i.t if a is mapped 1 then no char is mapped ot 1 and a is not map to any other number 
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
void print(map<char, int> &mp)
{
    for (auto val : mp)
    {
        cout << val.first << "-" << val.second << "-";
    }
    cout << en;
}
bool isMappingPossible(string wa, string wb, string wc, map<int, char> &nums, map<char, int> &mp)
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int mult = 1;
    for (int i = wa.size() - 1; i >= 0; i--)
    {
        num1 += (mult * mp[wa[i]]);
        mult *= 10;
    }
    mult = 1;
    for (int i = wb.size() - 1; i >= 0; i--)
    {
        num2 += (mult * mp[wb[i]]);
        mult *= 10;
    }
    mult = 1;
    for (int i = wc.size() - 1; i >= 0; i--)
    {
        num3 += (mult * mp[wc[i]]);
        mult *= 10;
    }
    if (num1 + num2 == num3)
        return true;
    return false;
}
void sol(string wa, string wb, string wc, int curr, string dis_str, map<int, char> &nums, map<char, int> &mp)
{
    if (curr >= mp.size())
    {
        if (isMappingPossible(wa, wb, wc, nums, mp))
            print(mp);
        return;
    }
    char ch = dis_str[curr];
    for (int i = 0; i < 10; i++)
    {
        if (mp[ch] == -1 && nums[i] == '-')
        {
            mp[ch] = i;
            nums[i] = ch;
            sol(wa, wb, wc, curr + 1, dis_str, nums, mp);
            nums[i] = '-';
            mp[ch] = -1;
        }
    }
}
int main()
{
    FAST;
    string wa, wb, wc;
    cin >> wa >> wb >> wc;
    map<char, int> mp;
    map<int, char> nums;
    for (auto ch : wa)
        mp[ch] = -1;
    for (auto ch : wb)
        mp[ch] = -1;
    for (auto ch : wc)
        mp[ch] = -1;
    for (int i = 0; i < 10; i++)
    {
        nums[i] = '-';
    }
    string dis_str = "";
    for (auto ch : mp)
    {
        dis_str.push_back(ch.first);
    }

    sol(wa, wb, wc, 0, dis_str, nums, mp);
    return 0;
}