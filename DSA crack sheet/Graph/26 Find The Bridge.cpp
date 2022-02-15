/*

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int dfs(int x, vector<int> adj[], int c, int d, vector<int> &vis)
{
    vis[x] = 1;
    for (auto it : adj[x])
    {
        if (!vis[it] && (x != c || it != d))
            dfs(it, adj, c, d, vis);
    }
    return 0;
}
int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<int> vis(V, 0);
    dfs(c, adj, c, d, vis);
    return !vis[d];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;

    return 0;
}