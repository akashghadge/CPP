/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

Constraints:

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000

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
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int max_sub_till_now = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (pairs[j][1] < pairs[i][0])
                max_sub_till_now = max(max_sub_till_now, dp[j]);
        }
        dp[i] = max_sub_till_now + 1;
    }

    return *max_element(dp.begin(), dp.end());
}
int main()
{
    FAST;

    return 0;
}