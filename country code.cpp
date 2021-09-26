#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int countOfLetter(string str, char code)
{
    int c = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == code)
            c++;
    }
    return c;
}
int main()
{
    FAST;
    string str;
    char code;
    cin >> str;
    cin >> code;
    cout << countOfLetter(str, code) << en;
    return 0;
}