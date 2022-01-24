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
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void util(v<v<pii>> g, int src, int dest, vi &visited, string curr)
{
    if (src == dest)
    {
        cout << curr << en;
        return;
    }
    else if (visited[src])
        return;
    visited[src] = true;
    for (auto nbr : g[src])
    {
        if (visited[nbr.first])
            continue;
        util(g, nbr.first, dest, visited, curr + to_string(nbr.first));
    }
    visited[src] = false;
}
void all_paths(v<v<pii>> g, int src, int dest, vi visited)
{
    util(g, src, dest, visited, to_string(src));
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
    all_paths(graph, src, dest, visited);
    return 0;
}