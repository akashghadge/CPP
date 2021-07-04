/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
bool check(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    int i = 0, j = str1.size() - 1;
    while (i < str1.size())
    {
        if (str1[i] != str2[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool areRotations(string s1, string s2)
{
    // Your code here
    if (s1.size() != s2.size())
        return false;
    s1 += s1;
    int val = s1.find(s2);
    if (val == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << check(str1, str2);
    return 0;
}