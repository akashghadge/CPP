/*
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes arr[] and n as input parameters and returns the minimum possible sum. As the number can be large, return string presentation of the number without leading zeroes.
 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 107
0 ≤ Arri ≤ 9


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
    string addStrings(string X, string Y)
    {
        int i = X.size() - 1, j = Y.size() - 1;

        string res = "";

        int carry = 0;
        while (i >= 0 and j >= 0)
        {
            int digit1 = X[i] - '0';
            int digit2 = Y[j] - '0';

            int cal = (digit1 + digit2 + carry) % 10;
            carry = (digit1 + digit2 + carry) / 10;

            res = to_string(cal) + res;

            i--;
            j--;
        }

        while (i >= 0)
        {
            int digit1 = X[i] - '0';

            int cal = (digit1 + carry) % 10;
            carry = (digit1 + carry) / 10;

            res = to_string(cal) + res;

            i--;
        }

        while (j >= 0)
        {
            int digit2 = Y[j] - '0';

            int cal = (digit2 + carry) % 10;
            carry = (digit2 + carry) / 10;

            res = to_string(cal) + res;

            j--;
        }

        if (carry != 0)
        {
            res = to_string(carry) + res;
        }

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != '0')
            {
                return res.substr(i);
            }
        }

        return "0";
    }
    string solve(int arr[], int n)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
                pq.push(arr[i]);
        }
        string num1 = "";
        string num2 = "";
        while (!pq.empty())
        {
            if (pq.size())
            {
                string temp = to_string(pq.top());
                num1 += (temp);
                pq.pop();
            }
            if (pq.size())
            {
                string temp = to_string(pq.top());
                num2 += (temp);
                pq.pop();
            }
        }
        // reverse(num1.begin(),num1.end());
        // reverse(num2.begin(),num2.end());
        return addStrings(num1, num2);
    }
};
int main()
{
    FAST;

    return 0;
}