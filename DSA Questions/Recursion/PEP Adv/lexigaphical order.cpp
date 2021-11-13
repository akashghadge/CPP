/*
1
10
100
1000
....


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
void sol(int start, int n)
{
    if (start > n)
        return;
    cout << start << en;
    for (int i = 0; i < 10; i++)
    {
        sol(10 * start + i, n);
    }
}
int main()
{
    FAST;
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
        sol(i, n);
    }

    return 0;
}