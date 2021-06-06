/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
Accepted
513,947
Submissions
1,529,490

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string word;
        vector<string> str;
        while (ss >> word)
        {
            str.push_back(word);
        }
        if (str.size() == 0)
        {
            return 0;
        }
        return str[str.size() - 1].size();
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}