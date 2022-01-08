/*
You are given a binary string S of length N. Your task is to check if there exists a substring of S which is the binary representation of a prime number.

Formally, check if there exist integers L and R such that 1≤L≤R≤N, and the substring SLSL+1SL+2…SR, when treated as a binary integer, is prime.

Print "Yes" if such a substring exists, and "No" if it doesn't.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each testcase consists of a single line of input, containing a binary string S.
Output Format
For each test case, output a single line containing one string — "Yes" or "No", the answer to the problem.

You may print each character of the answer in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤2.5⋅104
|S|≤105
The sum of |S| over all tests does not exceed 3⋅105
Subtasks
Subtask 1 (30 points):

1≤T≤103
|S|≤10
Subtask 2 (70 points):

Original constraints
Sample Input 1 
3
1
111
101101
Sample Output 1 
No
Yes
Yes
Explanation
Test case 1: There is only one substring, namely "1", and it isn't prime.

Test case 2: The substrings of the given string are {"1", "11", "111", "1", "11", "1"}. Of these, "111" which represents 7 in binary, and "11" which represents 3 in binary, are primes.

Test case 3: One of the substrings of the string is "1101", which is the binary representation of 13 — a prime.


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

int sol(string str)
{
    int n = str.size();
    if (n == 1)
        return false;
    int ones = 0;
    int zeros = 0;
    for (auto ch : str)
    {
        if (ch == '1')
            ones++;
        else
            zeros++;
    }
    if (zeros == n)
        return false;
    if (zeros == n - 1 && str[n - 1] == '1')
        return false;
    return true;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        sol(str) ? cout << "Yes" : cout << "No";
        cout << en;
    }

    return 0;
}