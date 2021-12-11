/*
    here we have polygon of n vertices
    print how many ways can we can seprate in triangles

    by observation we can reduce it to catlan
    n = 1 we can't make triangles 0
    n = 2 we can't make triangles 1
    n = 3 we can't make triangles 1
    n = 4 we can't make triangles 2
    n = 5 we can't make triangles 5
    n = 6 we can't make triangles 14
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
int polygons(int n)
{
    n -= 2;
    if (n <= 0)
        return 0;
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 0;
        int r = i - 1;
        while (l < i)
        {
            dp[i] += (dp[l] * dp[r]);
            l++;
            r--;
        }
    }
    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << polygons(n) << en;
}