/*
    now we have n plots at both sides of road
    and same as binary string we can't place building together
    so we use prev methods and multiply it so we get total combinations
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
    int ans = sol(n);
    cout << ans * 1ll * ans << en;
    return 0;
}