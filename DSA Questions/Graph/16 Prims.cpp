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
void sol(v<v<pii>> graph, int src)
{
    vi visited(graph.size());
    priority_queue<Node *, vector<Node *>, compare> pq;
    pq.push(new Node(src, -1, 0));

    while (pq.size() > 0)
    {
        Node *node = pq.top();
        pq.pop();
        if (visited[node->src])
            continue;

        visited[node->src] = true;
        if (node->parent != -1)
            cout << node->src << " " << node->parent << " " << node->wt << en;

        for (auto nbr : graph[node->src])
        {
            if (visited[nbr.first])
                continue;
            pq.push(new Node(nbr.first, node->src, nbr.second));
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
    cin >> src;
    sol(graph, src);
    return 0;
}