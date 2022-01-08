/*
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 
Example 2:

Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges

Your Task:  
You don't need to read input or print anything. Complete the function minimumCost() which takes N, W, and array cost as input parameters and returns the minimum value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N, W ≤ 2*102
-1 ≤ cost[i] ≤ 105
cost[i] ≠ 0


*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{

public:
    int minimumCost(int arr[], int n, int w)
    {
        // Your code goes here
        int dp[n + 1][w + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 1e9;
                }
                else if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i <= j && arr[i - 1] != -1)
                {
                    dp[i][j] = min(arr[i - 1] + dp[i][j - i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][w] != 1e9)
            return dp[n][w];
        return -1;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends