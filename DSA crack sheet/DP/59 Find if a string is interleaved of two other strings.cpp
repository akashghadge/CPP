/*
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.

Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.
Your Task:
Complete the function isInterleave() which takes three strings A, B and C as input and returns true if C is an interleaving of A and B else returns false. (1 is printed by the driver code if the returned value is true, otherwise 0.)

Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B

Constraints:
1 ≤ length of A, B ≤ 100
1 ≤ length of C ≤ 200


*/
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    bool isInterleave(string A, string B, string C)
    {
        int a = A.length(), b = B.length(), c = C.length();
        if (a + b != c)
            return false;
        bool dp[a + 1][b + 1];
        dp[0][0] = true;
        // initial fill
        for (int i = 1; i <= a; i++)
            dp[i][0] = (dp[i - 1][0] && A[i - 1] == C[i - 1]);
        for (int j = 1; j <= b; j++)
            dp[0][j] = (dp[0][j - 1] && B[j - 1] == C[j - 1]);

        // actual solving
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i + j - 1]) ||
                           (dp[i][j - 1] && B[j - 1] == C[i + j - 1]);
            }
        }
        return dp[a][b];
    }
};

class Solution
{
public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C)
    {
        //Your code here
        string str1 = A + B;
        string str2 = B + A;
        bool flag = false;
        int i = 0, j = 0;
        while (i < str1.size() && j < C.size())
        {
            if (str1[i] == C[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == C.size())
            flag = true;

        i = 0;
        j = 0;
        while (i < str2.size() && j < C.size())
        {
            if (str2[i] == C[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == C.size())
            flag = true;
        return flag;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends
