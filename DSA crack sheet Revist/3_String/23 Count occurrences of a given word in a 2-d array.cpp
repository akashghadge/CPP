/*

*/
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<char>> &mat, vector<vector<int>> vis, int r, int c, string target, int id)
{
    // string is completed
    if (r < 0 or c < 0 or c >= mat[0].size() or r >= mat.size() or vis[r][c] or mat[r][c] != target[id])
        return 0;
    if (id == target.size() - 1)
    {
        return 1;
    }
    vis[r][c] = 1;
    int curr = 0;
    curr += dfs(mat, vis, r + 1, c, target, id + 1);
    curr += dfs(mat, vis, r, c + 1, target, id + 1);
    curr += dfs(mat, vis, r - 1, c, target, id + 1);
    curr += dfs(mat, vis, r, c - 1, target, id + 1);
    return curr;
}
int findOccurrence(vector<vector<char>> &mat, string target)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += dfs(mat, vis, i, j, target, 0);
        }
    }
    return ans;
}
int main()
{
}