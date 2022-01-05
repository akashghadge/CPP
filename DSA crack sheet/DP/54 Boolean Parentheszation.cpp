/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200 


*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/*
35
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F

 */
#define vi vector<int>
#define vii vector<vector<int>>
class Solution
{
public:
    int mod = 1003;
    int boolean_parenthesis(string values, string operands)
    {
        int n = values.size();
        int m = operands.size();
        vii true_dp(n, vi(n));
        vii false_dp(n, vi(n));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; j++, i++)
            {
                if (gap == 0)
                {
                    char curr_char = values[i];
                    if (curr_char == 'T')
                    {
                        true_dp[i][j] = true;
                        false_dp[i][j] = false;
                    }
                    else
                    {
                        true_dp[i][j] = false;
                        false_dp[i][j] = true;
                    }
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        char curr_operator = operands[k];
                        int true_left = true_dp[i][k];
                        int true_right = true_dp[k + 1][j];
                        int false_left = false_dp[i][k];
                        int false_right = false_dp[k + 1][j];

                        if (curr_operator == '&')
                        {
                            true_dp[i][j] += ((true_left % mod) * (true_right % mod)) % mod;
                            false_dp[i][j] += (true_left * false_right) % mod + (true_right * false_left) % mod + (false_left * false_right) % mod;
                        }
                        else if (curr_operator == '|')
                        {
                            true_dp[i][j] += (true_left * false_right) % mod + (true_right * false_left) % mod + (true_left * true_right) % mod;
                            false_dp[i][j] += (false_left * false_right) % mod;
                        }
                        else if (curr_operator == '^')
                        {
                            true_dp[i][j] += (true_left * false_right) % mod + (true_right * false_left) % mod;
                            false_dp[i][j] += (true_left * true_right) % mod + (false_left * false_right) % mod;
                        }
                    }
                }
            }
        }
        return true_dp[0][n - 1];
    }

    int countWays(int N, string S)
    {
        // code here
        string values = "";
        string operands = "";
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'T' || S[i] == 'F')
                values.push_back(S[i]);
            else
                operands.push_back(S[i]);
        }
        // cout<<values<<operands<<endl;
        return boolean_parenthesis(values, operands) % 1003;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends