/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
 

Your Task:  
You don't need to read input or print anything. Complete the function isPlaindrome() which accepts string S and returns a boolean value


Expected Time Complexity: O(Length of S) 
Expected Auxiliary Space: O(1) 


Constraints:
1 <= Length of S <= 105


*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    int isPlaindrome(string S)
    {
        // Your code goes here
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (S[i] != S[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}