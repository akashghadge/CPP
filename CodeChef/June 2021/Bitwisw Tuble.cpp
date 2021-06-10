/*
Chef has two numbers N and M. Help Chef to find number of integer N-tuples (A1,A2,…,AN) such that 0≤A1,A2,…,AN≤2M−1 and A1&A2&…&AN=0, where & denotes the bitwise AND operator.

Since the number of tuples can be large, output it modulo 109+7.

Input
The first line contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers N and M.
Output
For each test case, output in a single line the answer to the problem modulo 109+7.

Constraints
1≤T≤105
1≤N,M≤106
Subtasks
Subtask #1 (100 points): original constraints

Sample Input
4
1 2
2 2
4 2
8 4
Sample Output
1
9
225
228250597
Explanation
Test Case 1: The only possible tuple is (0).

Test Case 2: The tuples are (0,0), (0,1), (0,2), (0,3), (1,0), (2,0), (3,0), (1,2), (2,1).


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
// varible
ll n;
ll m;
ll powerLog(ll base, ll p)
{
    long long res = 1; // Initialize result
    long long M = 1e9 + 7;
    while (p > 0)
    {
        // If y is odd, multiply x with result
        if (p & 1)
            res = ((res % M) * (base % M)) % M;

        // n must be even  now
        p = p >> 1;                           // y = y/2
        base = ((base % M) * (base % M)) % M; // Change x to x^2
    }
    return res;
}
ll sol()
{
    ll base = powerLog(2, n);
    return powerLog(--base, m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m;
        cout << sol() << en;
    }

    return 0;
}