/*
we have n peoples and k teams distrubute them
k subsets partition
*/
/*
as we see in recursion
nth element have two choices okay
either fit into preexisting team
or make own team
for this choices
we can say that
n element tell n-1 person 
1) make k teams and i will adjust in it
2) make k-1 teams and i will make my own team

so here in first possibility nth have choice of choosing team so it will produce (k*(n-1)) options
and in the second possibility making own team only make n-1 options
so 
we can say that
formula is
dp[team][person]= teams * dp[team][person-1](n-1 make k teams and i will adjust) 
+ dp[team-1][person -1] (n-1 make k-1 teams and i will make my seprate team) 
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
int sol(int n, int k)
{
    if (k > n)
        return 0;
    else if (k == n)
        return 1;

    vii dp(k + 1, vi(n + 1));
    for (int teams = 1; teams <= k; teams++)
    {
        for (int persons = 1; persons <= n; persons++)
        {
            if (teams == persons)
                dp[teams][persons] = 1;
            else if (teams > persons)
                dp[teams][persons] = 0;
            else
            {
                dp[teams][persons] = (teams * dp[teams][persons - 1]) + dp[teams - 1][persons - 1];
            }
        }
    }
    return dp[k][n];
}
int main()
{
    FAST;
    int n, k;
    cin >> n >> k;
    cout << sol(n, k) << en;
    return 0;
}