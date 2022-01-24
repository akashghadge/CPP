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
void dfs(vii grid, int i, int j, int n, int m, vii &visited)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j])
        return;

    visited[i][j] = true;
    dfs(grid, i + 1, j, n, m, visited);
    dfs(grid, i - 1, j, n, m, visited);
    dfs(grid, i, j + 1, n, m, visited);
    dfs(grid, i, j - 1, n, m, visited);
}
int sol(vii grid, int n, int m)
{
    int ans = 0;
    vii visited(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] || grid[i][j])
                continue;
            ans++;
            dfs(grid, i, j, n, m, visited);
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
    int N, M;
    cin >> N >> M;
    vector<vi> grid(N, vi(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << sol(grid, N, M) << en;
    return 0;
}