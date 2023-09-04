/*
https://cp-algorithms.com/string/prefix-function.html

For example, prefix function of string "abcabcd" is  
$[0, 0, 0, 1, 2, 3, 0]$ , and prefix function of string "aabaaab" is  
$[0, 1, 0, 1, 2, 2, 3]$.

so basically phi[i] is at that point take not at that point this for abcabcd for index 5 abcabc is string so abc and abc is proper prefix and suffix and take suffix also left to right not right to left

First optimization
The first important observation is, that the values of the prefix function can only increase by at most one.


Second optimization
KMP algorithm improves efficiency by avoiding unnecessary character comparisons. It uses the prefix function to determine the longest matching substring within the pattern, allowing it to skip ahead intelligently when comparing the pattern with itself. This approach significantly speeds up the computation of the prefix function.
*/
#include <bits/stdc++.h>
using namespace std;
int lps(string s)
{
    // Your code goes here
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    int longestPrefixSuffix = pi[n - 1];
    if (longestPrefixSuffix == 0)
        return 0;
    return min(longestPrefixSuffix, n - 1);
}
int main()
{
}