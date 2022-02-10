/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.



Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.


Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
Accepted
63,218
Submissions
110,661

*/

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
    void dfs(int src, vector<vector<int>> &graph, vector<int> &visited)
    {
        if (visited[src])
            return;
        visited[src] = true;
        for (auto nbr : graph[src])
        {
            if (visited[nbr])
                continue;
            dfs(nbr, graph, visited);
        }
    }
    int sol(vector<vector<int>> &connections, int computers)
    {
        // graph is not possible
        if (connections.size() < computers - 1)
            return -1;

        // making of the graph
        vector<vector<int>> graph(computers);
        for (int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        // connected components
        vector<int> visited(computers);
        int comp = 0;
        for (int i = 0; i < computers; i++)
        {
            if (visited[i])
                continue;
            dfs(i, graph, visited);
            comp++;
        }
        return comp - 1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;
    int vtx, e;
    cin >> vtx >> e;
    vii edge(e, vi(2));
    for (int i = 0; i < e; i++)
    {
        cin >> edge[i][0] >> edge[i][1];
    }
    Solution *s = new Solution();
    cout << s->sol(edge, vtx) << en;

    return 0;
}