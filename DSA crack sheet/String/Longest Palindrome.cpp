/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ |S| ≤ 103


*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
// this is my approch to solve this problem there is also dp arrpch there but it require space
// so here simply i check all possible substrings for this thing
// brute force and all test caese are pass :) x)
bool checkPal(string &S, int i, int j)
{
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
string longestPalin(string S)
{
    // code here
    int ll = -1;
    string ans = "";
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i; j < S.size(); j++)
        {
            if (checkPal(S, i, j))
            {
                if (ll < (j - i))
                {
                    ll = j - i;
                    ans = S.substr(i, (j + 1 - i));
                }
            }
        }
    }
    // cout<<ll<<endl;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}