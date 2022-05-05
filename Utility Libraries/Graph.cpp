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
class Undirected_Graph
{
public:
    vii graph;
    int n;
    // declaration of graph
    Undirected_Graph(vii graph)
    {
        this->graph = graph;
    }
    Undirected_Graph(int n)
    {
        graph.resize(n);
        this->n = n;
    }
    Undirected_Graph(int n, vpi edges)
    {
        graph.resize(n);
        this->n = n;
        for (auto edge : edges)
        {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
    }
    void AddEdge(pii edge)
    {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    bool DeleteEdge(pii edge)
    {
        int id = -1;
        for (int i = 0; i < graph[edge.first].size(); i++)
            if (edge.second == graph[edge.first][i])
                id = i;
        if (id != -1)
            graph[edge.first].erase(graph[edge.first].begin() + id);

        id = -1;
        for (int i = 0; i < graph[edge.second].size(); i++)
            if (edge.first == graph[edge.second][i])
                id = i;
        if (id != -1)
            graph[edge.second].erase(graph[edge.second].begin() + id);

        return id != -1;
    }

    bool dfs_find(int src, int dest)
    {
        stack<int> st;
        st.push(src);
        vi visited(n, 0);
        while (st.size())
        {
            int curr = st.top();
            st.pop();
            if (visited[curr])
                continue;
            if (curr == dest)
                return true;
            visited[curr] = true;
            for (auto nbr : graph[curr])
                st.push(nbr);
        }
        return false;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    vpi edges_arr(edges);
    for (int i = 0; i < edges; i++)
    {
        cin >> edges_arr[i].first >> edges_arr[i].second;
    }

    Undirected_Graph g(n, edges_arr);
    cout << g.dfs_find(0, 5) << en;
    g.AddEdge({4, 5});
    cout << g.dfs_find(0, 5) << en;
    g.DeleteEdge({4, 5});
    cout << g.dfs_find(0, 5) << en;
    g.AddEdge({4, 5});
    cout << g.dfs_find(0, 5) << en;
}