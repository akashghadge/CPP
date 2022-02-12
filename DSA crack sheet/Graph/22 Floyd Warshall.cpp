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

vector<vector<int>> floyd_warshal(vector<vector<pair<int, int>>> graph, int vertex)
{
    vector<vector<int>> ans(vertex, vector<int>(vertex));
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            if (i != j)
                ans[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < vertex; i++)
    {
        int node = i;
        for (auto p : graph[i])
        {
            ans[i][p.first] = p.second;
        }
    }

    for (int k = 0; k < vertex; k++)
    {
        for (int i = 0; i < vertex; i++)
        {
            for (int j = 0; j < vertex; j++)
            {
                if (ans[i][k] != INT_MAX && ans[k][j] != INT_MAX)
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    return ans;
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