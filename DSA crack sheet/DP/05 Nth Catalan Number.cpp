/*

*/
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
int findCatalan(int n)
{
    int manade[n + 1] = {0};
    manade[0] = manade[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            manade[i] += manade[j] * manade[i - j - 1];
        }
    }
    return manade[n];
}
int main()
{
    FAST;
    return 0;
}