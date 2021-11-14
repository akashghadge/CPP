/*
aabb
have 
a a b b
aa b b
aa bb
a a bb
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
void print(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}
bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void sol(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << en;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        string curr_chunk = str.substr(0, i + 1);
        string remaining = str.substr(i + 1);
        if (isPalindrome(curr_chunk))
        {
            sol(remaining, ans + "(" + curr_chunk + ")");
        }
    }
}
int main()
{
    FAST;
    string str;
    cin >> str;
    sol(str, "");
    return 0;
}