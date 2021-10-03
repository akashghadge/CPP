/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 105


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
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        //special case
        if (p.length() > s.length())
            return "-1";

        unordered_map<char, int> mp;
        for (char &c : p)
            mp[c]++;

        int count = mp.size();

        int n = s.length(), startIdx = -1, winLen = INT_MAX;

        int i = 0, j = 0;

        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;

                if (mp[s[j]] == 0)
                    count--;
            }

            if (count == 0)
            {
                while (count == 0)
                {
                    if (mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;

                        if (mp[s[i]] == 1)
                            count++;
                    }
                    i++;
                }

                if (winLen > j - i + 2)
                {
                    winLen = j - i + 2;
                    startIdx = i - 1;
                }
            }

            j++;
        }

        if (winLen == INT_MAX)
            return "-1";
        else
            return s.substr(startIdx, winLen);
    }
};
int main()
{
    FAST;

    return 0;
}