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
bool isCyclic(vii graph)
{
    queue<int> q;
    vi visited(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i])
            continue;
        q.push(i);
        while (q.size() != 0)
        {
            // r m* w a*
            int node = q.front();
            q.pop();
            if (visited[node])
                return true;
            visited[node] = true;
            // cout << node << en;
            for (auto nbr : graph[node])
            {
                if (!visited[nbr])
                    q.push(nbr);
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
    vii graph(vertexes);
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    isCyclic(graph) ? cout << "YES" : cout << "NO";
    cout << en;
    return 0;
}