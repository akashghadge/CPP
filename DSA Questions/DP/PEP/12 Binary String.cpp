/*
binary string of n length which does not contain consecative zeros's
ie. 
1001 is not allowed
we have n and we need to give count of that kind of strings
*/
/*
here basically we are starting new categories of problems i.e. exlude include category

here we make two spaces 
one which gives count of strings which ends with 0
another which gives count of strings which ends with 1

here we have observation is 
we can make n th strigs which end with zero by getting all string which have last 1
i.e for 11 we can make to 110

we can make n th string which is end with one by simply adding 1 to all strings ;)
11 -> 111
01 -> 011
10 -> 101
cause 1 does not have effect
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
int sol(int n)
{
    int zero = 1;
    int one = 1;
    for (int i = 1; i < n; i++)
    {
        int prevOne = one;
        int prevZero = zero;
        one = prevOne + prevZero;
        zero = prevOne;
    }
    return one + zero;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << sol(n) << en;
    return 0;
}