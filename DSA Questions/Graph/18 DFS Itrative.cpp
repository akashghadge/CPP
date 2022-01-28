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
void IterativeDFS(v<v<pii>> graph, int src, int dest)
{
    stack<int> q;
    q.push(src);
    vi visited(graph.size(), 0);
    while (q.size() != 0)
    {
        // r m* w a*
        int node = q.top();
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        cout << node << en;

        for (auto nbr : graph[node])
        {
            if (!visited[nbr.first])
                q.push(nbr.first);
        }
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
    int src, dest;
    cin >> src >> dest;
    IterativeDFS(graph, src, dest);
    return 0;
}