/*
Here we have string of only abc 
and we need get count of subsequences which match below regular expresion
a+b+c+
i.e 1 a or more a _ 1 b or mor b + 1 c or more c
e.g.
abc
aabc
aabbc
aabbcc
aabcc
...
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
int sol(string str)
{
    int n = str.size();
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        char curr = str[i];
        if (curr == 'a')
        {
            a = a * 2 + 1;
        }
        else if (curr == 'b')
        {
            b = b * 2 + a;
        }
        else
        {
            c = c * 2 + b;
        }
    }
    return c;
}
int main()
{
    FAST;
    string str;
    cin >> str;
    cout << sol(str) << en;
    return 0;
}