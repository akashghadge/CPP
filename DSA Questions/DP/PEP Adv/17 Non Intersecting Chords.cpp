/*
here we have 2n chords 
print in how many ways we can have chords in circle such that no one intersects


here we solve it using catlan cause 
if we see in observations 
n = 1 means we have 2 points and only 1 way possible
n = 2 means we have 4 points and  2 way possible
n = 3 means we have 6 points and  5 way possible
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
int chords(int n)
{
    if (n == 0)
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
    cout << chords(n) << en;
}