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
int CycleSize(vii graph)
{
    queue<pair<int, int>> q;
    vi visited(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i])
            continue;
        q.push({i, 1});
        while (q.size() != 0)
        {
            // r m* w a*
            pii node = q.front();
            q.pop();
            if (visited[node.first])
                return node.second;
            visited[node.first] = true;
            // cout << node << en;
            for (auto nbr : graph[node.first])
            {
                if (!visited[nbr])
                    q.push({nbr, node.second + 1});
            }
        }
    }
    return 0;
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
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    (CycleSize(graph) % 2 == 0) ? cout << "YES" : cout << "NO";
    cout << en;
    return 0;
}