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
struct Node
{
    int src, wt;
    int parent;
    Node(int s, int p, int w)
    {
        src = s;
        wt = w;
        parent = p;
    }
};
struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return p1->wt > p2->wt;
    }
};
void TopologicalSortUtil(v<v<pii>> graph, int src, stack<int> &st, vi &visited)
{
    if (visited[src])
        return;
    visited[src] = true;
    for (auto nbr : graph[src])
    {
        if (visited[nbr.first])
            continue;
        TopologicalSortUtil(graph, nbr.first, st, visited);
    }
    st.push(src);
}
void TopologicalSort(v<v<pii>> graph)
{
    stack<int> st;
    vi visited(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i])
            continue;
        TopologicalSortUtil(graph, i, st, visited);
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
    TopologicalSort(graph);
    return 0;
}