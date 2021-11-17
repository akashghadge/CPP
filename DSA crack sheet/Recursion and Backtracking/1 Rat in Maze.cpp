/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1


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
class Solution
{
public:
    void sol(vector<vector<int>> &grid, int size, int row, int col, vector<vector<bool>> &visited, string ans, vector<string> &res)
    {
        if (row < 0 || col < 0 || row == size || col == size || grid[row][col] == 0 || visited[row][col])
        {
            return;
        }
        if (row == size - 1 && col == size - 1)
        {
            res.push_back(ans);
            return;
        }

        visited[row][col] = true;
        sol(grid, size, row - 1, col, visited, ans + "D", res);
        sol(grid, size, row + 1, col, visited, ans + "U", res);
        sol(grid, size, row, col + 1, visited, ans + "R", res);
        sol(grid, size, row, col - 1, visited, ans + "L", res);
        visited[row][col] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<bool>> visited(n, vector<bool>(n));
        vector<string> res;
        sol(m, n, 0, 0, visited, "", res);
        sort(res.begin(), res.end());
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}