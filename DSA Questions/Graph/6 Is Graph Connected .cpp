#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define v vector
#define pii pair<int, int>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void dfs(v<v<pii>> &graph, int vt, vi &visited, vi &curr)
{
    if (visited[vt])
        return;
    curr.push_back(vt);
    visited[vt] = true;
    for (auto val : graph[vt])
    {
        if (visited[val.first])
            continue;
        dfs(graph, val.first, visited, curr);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;
    int vertexes, edges;
    cin >> vertexes >> edges;
    v<v<pii>> graph(vertexes);
    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    }
    vi visited(vertexes, false);
    vii comps;
    for (int i = 0; i < vertexes; i++)
    {
        if (visited[i])
            continue;
        vi curr;
        dfs(graph, i, visited, curr);
        comps.push_back(curr);
    }

    if (comps.size() == 1 && comps[0].size() == vertexes)
        cout << "true" << en;
    else
        cout << "false" << en;

    return 0;
}