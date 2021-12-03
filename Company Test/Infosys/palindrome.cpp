#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
int sol(string num)
{
    while (!isPalindrome(num))
    {
        int int1 = stoi(num);
        reverse(num.begin(), num.end());
        int int2 = stoi(num);
        int res = int1 + int2;
        num = to_string(res);
    }
    return stoi(num);
}
int main()
{
    FAST;
    string num;
    cin >> num;
    cout << sol(num) << en;
    return 0;
}