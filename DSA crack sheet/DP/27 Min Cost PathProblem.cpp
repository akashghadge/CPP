/*
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 500
1 ≤ Matrix[i][j] ≤ 1000


*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define vii vector<vector<int>>
#define vi vector<int>
class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        vii dp(n, vi(n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == n - 1)
                    dp[i][j] = mat[i][j];
                else if (j == 0)
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + mat[i][j];
                }
                else if (j == n - 1)
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1]) + mat[i][j];
                }
                else
                {
                    int temp = max(dp[i + 1][j], dp[i + 1][j - 1]);
                    dp[i][j] = max(temp, dp[i + 1][j + 1]) + mat[i][j];
                }
            }
        }
        int max_ans = 0;
        for (int i = 0; i < n; i++)
        {
            max_ans = max(max_ans, dp[0][i]);
        }
        return max_ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends