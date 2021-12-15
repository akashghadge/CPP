/*
here we have string of operands and the operator

values = TFTF
operands = &|^
this will make 
T & F | T ^  F
here we have choices to fill up parenthesis answer should be true
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
                        true_dp[i][j] += true_left * true_right;
                        false_dp[i][j] += true_left * false_right + true_right * false_left + false_left * false_right;
                    }
                    else if (curr_operator == '|')
                    {
                        true_dp[i][j] += true_left * false_right + true_right * false_left + true_left * true_right;
                        false_dp[i][j] += false_left * false_right;
                    }
                    else if (curr_operator == '^')
                    {
                        true_dp[i][j] += true_left * false_right + true_right * false_left;
                        false_dp[i][j] += true_left * true_right + false_left * false_right;
                    }
                }
            }
        }
    }
    return true_dp[0][n - 1];
}
int main()
{
    FAST;
    string values, operands;
    cin >> values >> operands;
    cout << boolean_parenthesis(values, operands) << en;
}