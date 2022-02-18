#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vii reverse_graph(vi adj[], int V)
{
    vii res(V);
    for (int i = 0; i < V; i++)
    {
        for (auto edge : adj[i])
        {
            res[edge].push_back(i);
        }
    }
    return res;
}
void dfss(int src, vi adj[], vector<bool> &visited, stack<int> &st)
{
    if (visited[src])
        return;
    visited[src] = true;
    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
            dfss(nbr, adj, visited, st);
    }
    st.push(src);
}

void dfs(int src, vii rev, vector<bool> &visited)
{
    if (visited[src])
        return;
    cout << src << " ";
    visited[src] = true;
    for (auto nbr : rev[src])
    {
        if (!visited[nbr])
            dfs(nbr, rev, visited);
    }
}

int strongly_connected(vector<int> adj[], int V)
{
    vector<bool> visited(V);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfss(i, adj, visited, st);
    }

    vii rev = reverse_graph(adj, V);
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!visited[curr])
        {
            dfs(curr, rev, visited);
            cout << en;
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
    int V, E;
    cin >> V >> E;
    vi adj[V];
    for (int i = 0; i < E; i++)
    {
        int vu, u;
        cin >> vu >> u;
        adj[vu].push_back(u);
    }
    strongly_connected(adj, V);
}