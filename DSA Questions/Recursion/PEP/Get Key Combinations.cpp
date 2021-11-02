/*
here we have key pad
1 abc
2 def
3 ghi
...

and if number given is 123
then we need to print 
adg adh adi aeg aeh aei ....
basically cross product
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
string codes[] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "wxyz"};
vector<string> sol(string num)
{
    if (num.size() == 0)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }
    char curr_char = num[0];
    num = num.substr(1);
    vector<string> rres = sol(num);
    vector<string> currRes;
    string codesForChar = codes[curr_char - '0'];
    for (int i = 0; i < codesForChar.size(); i++)
    {
        char curr_char_code = codesForChar[i];
        for (string rresString : rres)
        {
            currRes.push_back(curr_char_code + rresString);
        }
    }
    return currRes;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}
int main()
{
    FAST;
    vector<string> res = sol("123");
    printVector(res);
    return 0;
}