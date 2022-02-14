/*
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.


Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.


Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.


Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)


Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.

Vi
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    class Node
    {
    public:
        int u, v, wt;
        Node(int ui, int vi, int wti)
        {
            u = ui;
            v = vi;
            wt = wti;
        }
    };
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        vector<Node> nodes;
        for (auto curr : edges)
        {
            nodes.push_back(Node(curr[0], curr[1], curr[2]));
        }
        int src = 0;
        int inf = 10000000;
        vector<int> dist(n, inf);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : nodes)
            {
                if (dist[it.u] + it.wt < dist[it.v])
                {
                    dist[it.v] = dist[it.u] + it.wt;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : nodes)
            {
                if (dist[it.u] + it.wt < dist[it.v])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends