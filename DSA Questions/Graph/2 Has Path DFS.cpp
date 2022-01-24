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
bool hasPath(v<v<pii>> g, int src, int dest, vi &visited)
{
    if (src == dest)
        return true;
    visited[src] = true;
    for (auto nbr : g[src])
    {
        if (!visited[nbr.first])
        {
            bool res = hasPath(g, nbr.first, dest, visited);
            if (res)
                return true;
        }
    }
    return false;
}
int main()
{
    FAST;
    int edges, vertexes;
    cin >> vertexes >> edges;
    v<v<pii>> graph(vertexes);
    for (int i = 0; i < edges; i++)
    {
        int vt1, vt2, wt;
        cin >> vt1 >> vt2 >> wt;
        graph[vt1].push_back({vt2, wt});
        graph[vt2].push_back({vt1, wt});
    }
    int src, dest;
    cin >> src >> dest;
    vi visited(vertexes, false);
    hasPath(graph, src, dest, visited) ? cout << "true" : cout << "false";
    cout << en;
    return 0;
}