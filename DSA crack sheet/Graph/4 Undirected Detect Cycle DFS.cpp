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
// Function to detect cycle in an undirected graph.
bool cycle_detect(vector<int> adj[], int s, vector<bool> &vis, int parent)
{
    vis[s] = 1;
    for (int u : adj[s])
    {
        if (vis[u] == false)
        {
            if (cycle_detect(adj, u, vis, s) == true)
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (cycle_detect(adj, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<int> graph[vertexes];
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    isCycle(vertexes, graph) ? cout << "YES" : cout << "NO";
    cout << en;
    return 0;
}