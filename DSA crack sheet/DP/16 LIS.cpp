/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 106


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
int longestSubsequence(int n, int arr[])
{
    // your code here
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int max_sub_till_now = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
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