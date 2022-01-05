/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200


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
int eggDrop(int egg, int floor)
{
    // your code here
    vii dp(egg + 1, vi(floor + 1));
    for (int i = 1; i <= egg; i++)
    {
        for (int j = 1; j <= floor; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int worst_case = INT_MAX;
                for (int br = j - 1, sr = 0; br >= 0; br--, sr++)
                {
                    int survive = dp[i][br];
                    int breaks = dp[i - 1][sr];
                    int curr_ans = max(survive, breaks);
                    worst_case = min(curr_ans, worst_case);
                }
                dp[i][j] = worst_case + 1;
            }
        }
    }
    return dp[egg][floor];
}
int main()
{
    FAST;

    return 0;
}