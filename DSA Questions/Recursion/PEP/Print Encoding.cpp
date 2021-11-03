/*
here we have string number and 1 is map to a and so on to z
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
void helper(string num, string curr)
{
    if (num.size() == 0)
    {
        cout << curr << en;
        return;
    }
    else if (num[0] == '0')
    {
        return;
    }
    int numInt = num[0] - '0';
    char temp = 'a' + numInt - 1;
    string currAns = curr + temp;
    helper(num.substr(1), currAns);
    if (num.size() >= 2)
    {
        int digit1 = num[0] - '0';
        int digit2 = num[1] - '0';
        int number = digit1 * 10 + digit2;
        if (number < 26)
        {
            char temp = 'a' + number - 1;
            string currAns = curr + temp;
            helper(num.substr(2), currAns);
        }
    }
}
void sol(string num)
{
    helper(num, "");
}
int main()
{
    FAST;
    sol("12103");
    return 0;
}