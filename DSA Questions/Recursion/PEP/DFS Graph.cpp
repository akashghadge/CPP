/*

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void helper(vector<vector<int>> grid, vector<vector<bool>> &visited, int sx, int sy, int dx, int dy, int n, int m, string path)
{
    if (sx < 0 or sy < 0 or sx >= n or sy >= m or grid[sx][sy] == 1 or visited[sx][sy])
    {
        return;
    }
    else if (sx == dx and sy == dy)
    {
        cout << path << en;
    }
    visited[sx][sy] = true;
    helper(grid, visited, sx - 1, sy, dx, dy, n, m, path + "t");
    helper(grid, visited, sx, sy + 1, dx, dy, n, m, path + "r");
    helper(grid, visited, sx + 1, sy, dx, dy, n, m, path + "b");
    helper(grid, visited, sx, sy - 1, dx, dy, n, m, path + "l");
    visited[sx][sy] = false;
}
void sol(vector<vector<int>> grid, int sx, int sy, int dx, int dy, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m));
    helper(grid, visited, sx, sy, dx, dy, n, m, "");
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    FAST;
    int n, m;
    n = 3;
    m = 3;
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 0}};
    sol(arr, 0, 0, n - 1, 0, n, m);
    return 0;
}