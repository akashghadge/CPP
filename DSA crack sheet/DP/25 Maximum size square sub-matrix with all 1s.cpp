/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
Example 2:

Input: n = 2, m = 2
mat = {{0, 0}, 
       {0, 0}}
Output: 0
Explaination: There is no 1 in the matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and returns the size of the maximum square sub-matrix of given matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 50
0 ≤ mat[i][j] ≤ 1 


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int maxSquare(int N, int M, vector<vector<int>> grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    vii dp(n, vi(m));
    int ans = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid[i][j] == 0 || i == n - 1 || j == m - 1)
                dp[i][j] = grid[i][j];
            else
            {
                int temp_min = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = 1 + min(temp_min, dp[i + 1][j + 1]);
            }
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}
int main()
{
    FAST;

    return 0;
}