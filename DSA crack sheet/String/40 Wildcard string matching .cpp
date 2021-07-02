/*
Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

* --> Matches with 0 or more instances of any 
character or set of characters.
? --> Matches with any one character.
Example 1:

Input: wild = ge*ks
       pattern = geeks
Output: Yes
Explanation: Replace the '*' with 'e' to obtain 
the string.
Example 2:

Input: wild = ge?ks*
       pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' with 'e' and '*' with
'forgeeks' and it will be same as pattern.
Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

Expected Time Complexity: O(length of wild string + length of pattern string)
Expected Auxiliary Space: O(1)

Constraints:
1<=length of the two string<=10^3 


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}