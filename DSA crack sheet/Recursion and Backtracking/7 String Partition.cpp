/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

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
    bool isPalindrome(string str)
    {
        int i = 0, j = str.size() - 1;
        while (i <= j)
        {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void sol(string str, vector<string> ans, vector<vector<string>> &final_ans)
    {
        if (str.size() == 0)
        {
            final_ans.push_back(ans);
            return;
        }
        for (int i = 0; i < str.size(); i++)
        {
            string chunk = str.substr(0, i + 1);
            string rem = str.substr(i + 1);
            if (isPalindrome(chunk))
            {
                ans.push_back(chunk);
                sol(rem, ans, final_ans);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> final_ans;
        vector<string> ans;
        sol(s, ans, final_ans);
        return final_ans;
    }
};
int main()
{
    FAST;

    return 0;
}