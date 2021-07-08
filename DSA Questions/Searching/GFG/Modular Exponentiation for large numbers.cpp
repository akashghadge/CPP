/*
Implement pow(x, n) % M.
In other words, given x, n and M, find (xn) % M.
 

Example 1:

Input:
x = 3, n = 2, m = 4
Output:
1
Explanation:
32 = 9. 9 % 4 = 1.
Example 2:

Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.

Your Task:
You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n and M as input parameters and returns xn % M.
 

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)
 

Constraints:
1 ≤ x, n, M ≤ 109


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
long long int PowMod(long long int x, long long int n, long long int M)
{
    // Code here
    if (x == 1 || n == 0)
    {
        return 1;
    }
    long long ans = 1;
    while (n)
    {
        if ((n & 1) != 0)
        {
            ans = ((ans % M) * (x % M)) % M;
        }
        n = n >> 1;
        x = ((x % M) * (x % M)) % M;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}