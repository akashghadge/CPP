/*
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

Note: |s| represents the length of string s.

Constraints:
1 ≤ |a|,|b| ≤ 105


*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        // Your code here
        int n = a.size();
        int m = b.size();
        if (n != m)
            return false;
        // int x=0;
        // for(int i=0;i<m;i++)
        // {
        //     x^=a[i];
        //     x^=b[i];
        // }
        // return x==0;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < m; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
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