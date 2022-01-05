/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6
Explanation: 
We have following possible combinations:

 

Example 2:

Input:
N=2,  K=4
Output: 16

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted.(modulo 109 + 7)

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N ≤ 5000
1 ≤ K ≤ 100


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
long long countWays(int n, int k)
{
    // code here
    if (n == 1)
    {
        return k;
    }
    long long same = k;
    long long diff = k * (k - 1);
    long long total = same + diff;
    long long M = 1e9 + 7;
    for (int i = 3; i <= n; i++)
    {
        same = diff;
        diff = ((total) % M * ((k - 1)) % M) % M;
        total = (same + diff) % M;
    }
    return total;
}
int main()
{
    FAST;

    return 0;
}