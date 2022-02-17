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
class Solution
{
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> &graph, int u, int dst, int pu, int su, int maxsteps, vector<int> &cost, vector<int> &steps, int &mincost)
    {
        cost[u] = pu;
        steps[u] = su;
        if (u == dst)
        {
            mincost = min(mincost, pu);
            return;
        }
        for (auto p : graph[u])
        {
            int v = p.first, pv = p.second;
            if (1 + su <= maxsteps && pu + pv < mincost && (pu + pv < cost[v] || 1 + su < steps[v]))
                dfs(graph, v, dst, pu + pv, 1 + su, maxsteps, cost, steps, mincost);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        int mincost = INT_MAX;
        vector<int> cost(n, INT_MAX);
        vector<int> steps(n, INT_MAX);
        dfs(graph, src, dst, 0, 0, k + 1, cost, steps, mincost);
        return mincost == INT_MAX ? -1 : mincost;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;

    return 0;
}