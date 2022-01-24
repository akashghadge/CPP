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

    cout << "[";
    for (int i = 0; i < comps.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < comps[i].size(); j++)
        {
            if (j != comps[i].size() - 1)
                cout << comps[i][j] << ", ";
            else
                cout << comps[i][j];
        }
        cout << "]";
        if (i != comps.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}