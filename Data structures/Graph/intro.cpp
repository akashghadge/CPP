#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define mp make_pair
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// linked list class
template <class vecPrint>
void printVector(vector<vecPrint> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}
class Graph
{
protected:
    vector<vi> adj;
    int sizeOfGraph = 0;

public:
    Graph()
    {
        cin >> this->sizeOfGraph;
        vector<vi> adj(this->sizeOfGraph);
        int v, e;
        for (int i = 0; i < this->sizeOfGraph - 1; i++)
        {
            cin >> v >> e;
            adj[v].push_back(e);
            adj[e].push_back(v);
        }
        this->adj = adj;
    }
    Graph(vector<vi> adj)
    {
        this->adj = adj;
    }
    void allNodes()
    {
        int i = 0;
        for (auto list : this->adj)
        {
            cout << "Vertex of " << i << " have :";
            for (auto ele : list)
            {
                cout << ele << " ";
            }
            cout << en;
            i++;
        }
    }
    bool isConnected(int src, int des)
    {
        if (src == des)
            return true;

        stack<int> st;
        vector<bool> visited(this->sizeOfGraph, false);
        st.push(src);

        while (st.size() > 0)
        {
            // remove
            int curr = st.top();
            st.pop();
            // marked *
            if (visited[curr])
                continue;
            visited[curr] = true;
            // work

            //add
            for (auto nbr : this->adj[curr])
            {
                if (nbr == des)
                {
                    return true;
                }
                if (visited[nbr] == false)
                {
                    st.push(nbr);
                }
            }
        }
        return false;
    }
    vector<string> dfs()
    {
        vector<string> ans;
        int src = 0;
        stack<pair<int, string>> st;
        vector<bool> visited(this->sizeOfGraph, false);
        st.push(mp(src, to_string(src) + ""));
        while (st.size() > 0)
        {
            // remove
            pair<int, string> removed = st.top();
            st.pop();
            // marked *
            if (visited[removed.first])
                continue;
            visited[removed.first] = true;
            // work
            ans.push_back(to_string(removed.first) + "@" + removed.second);
            //add
            for (auto nbr : this->adj[removed.first])
            {
                if (visited[nbr] == false)
                {
                    st.push(mp(nbr, removed.second + to_string(nbr)));
                }
            }
        }
        return ans;
    }
    vector<string> bfs(int src)
    {
        vector<string> ans;
        if (src < 0 or src > this->sizeOfGraph - 1)
        {
            return ans;
        }
        queue<pair<int, string>> q;
        vector<bool> visited(this->sizeOfGraph, false);
        q.push(mp(src, to_string(src) + ""));

        while (q.size() > 0)
        {
            // remove
            pair<int, string> removed = q.front();
            q.pop();
            // marked *
            if (visited[removed.first])
                continue;
            visited[removed.first] = true;
            // work
            ans.push_back(to_string(removed.first) + "@" + removed.second);
            //add
            for (auto nbr : this->adj[removed.first])
            {
                if (visited[nbr] == false)
                {
                    q.push(mp(nbr, removed.second + to_string(nbr)));
                }
            }
        }
        return ans;
    }
    vector<string> bfs()
    {
        int src = 0;
        queue<pair<int, string>> q;
        vector<bool> visited(this->sizeOfGraph, false);
        q.push(mp(src, to_string(src) + ""));
        vector<string> ans;

        while (q.size() > 0)
        {
            // remove
            pair<int, string> removed = q.front();
            q.pop();
            // marked *
            if (visited[removed.first])
                continue;
            visited[removed.first] = true;
            // work
            ans.push_back(to_string(removed.first) + "@" + removed.second);
            //add
            for (auto nbr : this->adj[removed.first])
            {
                if (visited[nbr] == false)
                {
                    q.push(mp(nbr, removed.second + to_string(nbr)));
                }
            }
        }
        return ans;
    }
    int size()
    {
        return this->sizeOfGraph;
    }
};
int main()
{
    FAST;
    Graph g;
    cout << (g.isConnected(0, 2) ? "connected" : "not connected");
    // vector<string> ans = g.dfs();
    // g.allNodes();
    // printVector(ans);
}