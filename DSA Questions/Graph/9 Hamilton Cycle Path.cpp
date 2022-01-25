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
bool hashConnection(v<v<pii>> graph, int curr, int init)
{
    bool ans = false;
    for (auto nbr : graph[curr])
    {
        if (nbr.first == init)
            ans = true;
    }

    return ans;
}
void sol(v<v<pii>> graph, int src, string ans, unordered_set<int> &visited, int original)
{
    if (graph.size() - 1 == visited.size())
    {
        cout << ans;
        if (hashConnection(graph, src, original))
            cout << "*";
        else
            cout << ".";
        cout << en;
        return;
    }
    if (visited.find(src) != visited.end())
        return;
    visited.insert(src);
    for (auto nbr : graph[src])
    {
        if (visited.find(nbr.first) != visited.end())
            continue;
        sol(graph, nbr.first, ans + to_string(nbr.first), visited, original);
    }
    visited.erase(src);
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
        cin >> v1 >> v2;
        wt = 0;
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    }
    int src;
    cin >> src;
    unordered_set<int> visited;
    sol(graph, src, to_string(src), visited, src);

    return 0;
}