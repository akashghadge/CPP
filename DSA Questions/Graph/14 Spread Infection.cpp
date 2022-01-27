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
int sol(vii graph, int src, int t)
{
    vi visited(graph.size(), 0);
    queue<pii> q;
    q.push({src, 1});
    while (q.size() > 0)
    {
        pii node = q.front();
        q.pop();
        if (node.second > t)
            break;
        if (visited[node.first])
            continue;
        visited[node.first] = true;
        for (int nbr : graph[node.first])
        {
            if (!visited[nbr])
                q.push({nbr, node.second + 1});
        }
    }
    return accumulate(visited.begin(), visited.end(), 0);
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
    vii graph(vertexes);
    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int src, t;
    cin >> src >> t;
    cout << sol(graph, src, t) << en;
    return 0;
}