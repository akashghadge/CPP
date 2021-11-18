/*
123456
k =1
623451
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
void swap(string &str, int c, int j)
{
    char m = str[c];
    str[c] = str[j];
    str[j] = m;
}
void findMax(string str, int k, int c, string &max)
{
    if (c == str.size() - 1 or k <= 0)
        return;
    char m = str[c];
    for (int i = c + 1; i < str.size(); i++)
    {
        if (str[i] >= m)
            m = str[i];
    }
    if (str[c] == m)
    {
        findMax(str, k, c + 1, max);
    }
    else
    {
        for (int i = c + 1; i < str.size(); i++)
        {
            if (str[i] == m)
            {
                swap(str, i, c);
                if (str >= max)
                    max = str;
                findMax(str, k - 1, c + 1, max);
                swap(str, i, c);
            }
        }
    }
}
string findMaximumNum(string str, int k)
{
    string m = str;
    findMax(str, k, 0, m);
    return m;
}

int main()
{
    FAST;
    string num;
    int k;
    cin >> num >> k;
    return 0;
}