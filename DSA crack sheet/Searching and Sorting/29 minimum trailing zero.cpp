/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 104


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool predicate(int zerosReq, int n)
{
    if (n < 0)
        return false;

    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
        if (count >= zerosReq)
            return true;
    }
    return (count >= zerosReq);
}
int sol(int N)
{
    int low = 0;
    int high = 1e9;
    int mid = 0;
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (predicate(N, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    FAST;
    int N;
    cin >> N;
    cout << sol(N) << en;
    return 0;
}