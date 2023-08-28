/*

*/
#include <bits/stdc++.h>
using namespace std;

// like dp but we preprocess the max element
// time O(N^2) and space O(N^2)
int findMaxValue(vector<vector<int>> &arr, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
        dp[n - 1][i] = max(dp[n - 1][i + 1], arr[n - 1][i]);
    for (int i = n - 2; i >= 0; i--)
        dp[i][n - 1] = max(dp[i + 1][n - 1], arr[i][n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = max(arr[i][j], max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1])));
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            ans = max(ans, dp[i + 1][j + 1] - arr[i][j]);
        }
    }
    return ans;
}

// time O(N^2) and space O(N)
#define N 5

// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N])
{
    vector<int> temp1(N), temp2(N);
    temp1[N - 1] = mat[N - 1][N - 1];

    // Fill temp1
    for (int j = N - 2; j >= 0; j--)
        temp1[j] = max(temp1[j + 1], mat[N - 1][j]);

    // stores maximum value
    int maxValue = INT_MIN;

    // Iterate over the remaining rows
    for (int i = N - 2; i >= 0; i--)
    {
        // Initialize the last element of temp2
        temp2[N - 1] = max(temp1[N - 1], mat[i][N - 1]);
        for (int j = N - 2; j >= 0; j--)
        {
            // update temp2 and maxValue
            maxValue = max(maxValue, temp1[j + 1] - mat[i][j]);
            temp2[j] = max(
                {mat[i][j], temp1[j], temp2[j + 1]});
        }
        // Set temp1 to temp2 for the next iteration
        temp1 = temp2;
    }

    // Return the maximum value
    return maxValue;
}

int main()
{
}