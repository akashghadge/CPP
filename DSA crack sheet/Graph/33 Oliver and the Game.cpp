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
vector<vector<vector<int>>> ans(2, vii(100006, vi(100006, -1)));
bool dfs(vii &graph, int src, int dest, int par)
{
    if (src == dest)
        return true;
    bool flag = false;
    for (auto child : graph[src])
    {
        flag = flag || dfs(graph, child, dest, src);
    }
    return flag;
}
bool sol(vii &graph, int type, int x, int y)
{
    if (type == 0)
    {
        if (ans[type][x][y] != -1)
            return ans[type][x][y];
        ans[type][x][y] = dfs(graph, x, y, -1);
        return ans[type][x][y];
    }
    else
    {
        if (ans[type][y][x] != -1)
            return ans[type][y][x];
        ans[type][y][x] = dfs(graph, y, x, -1);
        return ans[type][y][x];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, t;
        cin >> u >> t;
        graph[u - 1].push_back(t - 1);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        sol(graph, type, x - 1, y - 1) ? cout << "YES" : cout << "NO";
        cout << en;
    }

    return 0;
}