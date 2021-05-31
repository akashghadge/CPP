/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
â€‹Example 2:

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
// here we check for all possible ans
bool check(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
string longestPalindrome(string str)
{
    int size = str.size();
    int maxL = -1;
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (check(str, i, j) && maxL < (j - i))
            {
                // cout << "hello" << endl;
                maxL = j - i;
                ans = str.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    cout << longestPalindrome(str) << en;
    return 0;
}