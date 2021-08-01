/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)


Constraints:
1 ≤ |S| ≤ 105


*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        // Your code here
        stack<int> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                s.push(str[i] - '0');
            }
            else
            {
                int n1 = s.top();
                s.pop();

                int n2 = s.top();
                s.pop();

                if (str[i] == '*')
                {
                    s.push(n1 * n2);
                }
                else if (str[i] == '/')
                {
                    s.push(n2 / n1);
                }
                else if (str[i] == '+')
                {
                    s.push(n1 + n2);
                }
                else if (str[i] == '-')
                {
                    s.push(n2 - n1);
                }
            }
        }

        return s.top();
    }
};
int main()
{
    FAST;

    return 0;
}