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
int main()
{
    FAST;
    int res = 1;
    for (int i = 0; i < 10; i++)
    {
        res = res << 1;
    }
    cout << res;

    return 0;
}