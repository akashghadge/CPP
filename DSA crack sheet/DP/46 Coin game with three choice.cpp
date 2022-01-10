/*
Given three numbers N, X, and Y. Geek and his friend playing a coin game. At the beginning, there are N coins. In each move, a player can pick X, Y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to check whether Geek will win the game or not if both are playing optimally.

Example 1:

Input: N = 5, X = 3, Y = 4
Output: 1
Explanation: There are 5 coins, every 
player can pick 1 or 3 or 4 coins on 
his/her turn. Geek can win by picking 
3 coins in first chance. Now 2 coins 
will be left so his frined will pick 
one coin and now Geek can win by 
picking the last coin.
Example 2:
Input: N = 2, X = 3, Y = 4
Output: 0
Explanation: Geek picks 1 and then 
his friend picks 1

Your Task:  
You don't need to read input or print anything. Complete the function findWinner() which takes N, X, and Y as input parameters and returns 1 if Geek can win otherwise 0.

Expected Time Complexity: O(|N|)
Expected Auxiliary Space: O(|N|)

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findWinner(int n, int x, int y)
    {
        // Your code goes here
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i - 1 >= 0 and !dp[i - 1])
                dp[i] = true;
            else if (i - x >= 0 and !dp[i - x])
                dp[i] = true;
            else if (i - y >= 0 and !dp[i - y])
                dp[i] = true;

            // Else A loses game.
            else
                dp[i] = false;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        Solution ob;
        cout << ob.findWinner(n, x, y);
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends