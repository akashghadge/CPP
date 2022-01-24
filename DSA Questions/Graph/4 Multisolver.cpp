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
/*
Smallest Path = 01256@28
Largest Path = 032546@66
Just Larger Path than 30 = 012546@36
Just Smaller Path than 30 = 01256@28
4th largest path = 03456@48
*/
void util(v<v<pii>> graph, int src, int dest, vi &visited, string curr, int cost, vector<pair<int, string>> &res)
{
    if (src == dest)
    {
        res.push_back({cost, curr});
        return;
    }
    else if (visited[src])
        return;

    visited[src] = true;
    for (auto nbr : graph[src])
    {
        if (visited[nbr.first])
            continue;
        util(graph, nbr.first, dest, visited, curr + to_string(nbr.first), cost + nbr.second, res);
    }

    visited[src] = false;
}
int multisolver(v<v<pii>> graph, int src, int dest, int just, int kth, vi &visited)
{
    vector<pair<int, string>> res;
    util(graph, src, dest, visited, to_string(src), 0, res);
    sort(res.begin(), res.end(),
         [](auto p1, auto p2)
         { return p1.first > p2.first; });

    int n = res.size();
    int sm = 0;
    int lg = 0;
    for (int i = 0; i < n; i++)
    {
        if (res[i].first < just)
        {
            sm = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (res[i].first > just)
        {
            lg = i;
            break;
        }
    }

    cout << "Smallest Path = " << res[n - 1].second << "@" << res[n - 1].first << en;
    cout << "Largest Path = " << res[0].second << "@" << res[0].first << en;
    cout << "Just Larger Path than " << just << " = " << res[lg].second << "@" << res[lg].first << en;
    cout << "Just Smaller Path than " << just << " = " << res[sm].second << "@" << res[sm].first << en;
    cout << kth << "th largest path = "
         << res[kth - 1].second << "@" << res[kth - 1].first << en;
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
    int src, dest, just, kth;
    cin >> src >> dest >> just >> kth;
    vi visited(vertexes, false);
    multisolver(graph, src, dest, just, kth, visited); 

    return 0;
} 