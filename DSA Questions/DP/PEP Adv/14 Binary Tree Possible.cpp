/*
here we have n nodes and we need to give 
how many bst's constructed with this n nodes
e.g
n=0  bst 1 (empty bst)
n=1  bst 1 (only node)
n=2  bst 2 (we have option to choose root)
*/
/*
here we use catlan numbers cause this series is same as catlan
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
int binary_tree_possible(int n)
{
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
    for (auto val : dp)
    {
        cout << val << " ";
    }
    cout << en;

    return dp[n];
}
int main()
{
    FAST;
    int n;
    cin >> n;
    cout << binary_tree_possible(n) << en;
}