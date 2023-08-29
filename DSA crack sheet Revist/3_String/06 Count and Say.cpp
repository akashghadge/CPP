/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n, string s = "1")
    {
        if (n == 1)
            return s;
        int i = 0, j, len = s.size();
        string ans = "";
        while (i < len)
        {
            j = i;
            while (i < len && s[i] == s[j])
                i++; // substring is [j,i-1] & "i-j" is the count
            ans += to_string(i - j) + s[j];
        }
        return countAndSay(n - 1, ans);
    }
};
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string s = countAndSay(n - 1);

        string t = "";

        int i = 0;
        int j = 1;
        if (s.length() == 1)
        {
            t.push_back(1 + '0');
            t.push_back(s[0]);
        }
        else
        {
            while (j <= s.length())
            {
                if (s[j] == s[j - 1])
                {
                    j++;
                }
                else if (s[j - 1] != s[j])
                {
                    t.push_back(j - i + '0');
                    t.push_back(s[i]);
                    i = j;
                    j++;
                }
            }
        }
        return t;
    }
};
int main()
{
}