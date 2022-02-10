// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool iscycle(int node, vector<int> adj[], vector<int> &visited, vector<int> &order)
    {
        visited[node] = 1;
        order[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                if (iscycle(it, adj, visited, order))
                    return true;
            }
            else if (order[it] == 1)
                return true;
        }
        order[node] = 0;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> adj[N];
        for (auto it : prerequisites)
            adj[it.second].push_back(it.first);
        vector<int> visited(N, 0);
        vector<int> order(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
                if (iscycle(i, adj, visited, order))
                    return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends