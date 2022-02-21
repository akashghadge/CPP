/*
Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
Source vertex should always be  0.

Example 1:

Input:
V = 4 , E = 3 and K = 8
A[] = [0, 1, 5, 1, 2, 1, 2, 3, 1]
Output: 0
Explanation:
There exists no path which has a distance
of 8.


Example 2:

Input:
V = 9, E = 14 and K = 60
A[] = [0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7,
11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9,
3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6,
8, 6, 7, 8, 7]
Output: 0
Explanation:




Your Task:
You don't need to read input or print anything. Your task is to complete the function pathMoreThanK() which takes the integer V, Edges E, an integer K and Array A which is having (Source, Destination, Weight) as input parameters and returns 1 if the path of at least k distance exists, else returns 0.

Expected Time Complexity: O(N!)
Expected Auxiliary Space: O(N)



Constraints:
2 ≤ V ≤ 5
1 ≤ E ≤ 20
1 ≤ K ≤ 100


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool helper(list<pair<int, int>> *adj, int src, vector<bool> &vis, int k)
{
    if (k <= 0)
    {
        return true;
    }
    vis[src] = true;
    for (auto nei : adj[src])
    {
        int v = nei.first;
        int wt = nei.second;
        if (vis[v] == false)
        {
            k -= wt;
            if (helper(adj, v, vis, k) == true)
            {
                return true;
            }
            k += wt; //
        }
    }
    vis[src] = false; //
    return false;
}
bool pathMoreThanK(int V, int E, int k, int *a)
{
    list<pair<int, int>> adj[V];
    for (int i = 0; i < E * 3; i += 3)
    {
        int u = a[i];
        int v = a[i + 1];
        int wt = a[i + 2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<bool> vis(V, false);
    return helper(adj, 0, vis, k);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;

    return 0;
}