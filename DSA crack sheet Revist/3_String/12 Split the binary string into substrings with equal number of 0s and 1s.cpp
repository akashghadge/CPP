/*

*/
#include <bits/stdc++.h>
using namespace std;
int maxSubStr(string str)
{
    // Write your code here
    int a = 0, b = 0, n = str.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            a++;
        else
            b++;
        if (a and a == b)
        {
            a = 0;
            b = 0;
            ans++;
        }
    }
    return (a or b) ? -1 : ans;
}
int main()
{
}