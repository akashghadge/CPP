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
int sol(int a, int b, int c)
{
    int diff1 = a - b;
    int diff2 = b - c;
    if (diff1 == diff2)
        return true;
    return false;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sol(a, b, c) ? cout << "YES" : cout << "NO";
        cout << en;
    }

    return 0;
}