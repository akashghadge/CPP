/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as inputs and returns the length of the smallest such string.


Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

 

Constraints:
1 ≤ |S| ≤ 105
String may contain both type of English Alphabets.


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
class Solution
{
public:
    string findSubString(string str)
    {
        // Your code goes here
        unordered_map<char, int> freq;
        for (char val : str)
        {
            freq[val]++;
        }
        int disEle = freq.size();
        int currCount = 0;
        freq.clear();
        int start = 0;

        int minLen = INT_MAX;
        int start_index = -1;
        for (int i = 0; i < str.size(); i++)
        {
            freq[str[i]]++;
            if (freq[str[i]] == 1)
            {
                currCount++;
            }
            if (currCount == disEle)
            {
                while (freq[str[start]] > 1)
                {
                    freq[str[start]]--;
                    start++;
                }
                // Update window size
                int len_window = i - start + 1;
                if (minLen > len_window)
                {
                    minLen = len_window;
                    start_index = start;
                }
            }
        }
        return str.substr(start_index, minLen);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}