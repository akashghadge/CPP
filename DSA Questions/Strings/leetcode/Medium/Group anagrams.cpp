/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        //         unordered_map<string,unordered_map<char,int>> mp;
        //         for(auto val:strs)
        //         {
        //             unordered_map<char,int> temp;
        //             for(char ch:val)
        //             {
        //                 temp[ch]++;
        //             }
        //             mp[val]=temp;
        //         }
        //         vector<vector<string>> ans;
        //         vector<bool> visited(strs.size(),false);
        //         for(int i=0;i<strs.size();i++)
        //         {
        //             if(visited[i]==true)
        //             {
        //                 continue;
        //             }
        //             vector<string> sub;
        //             sub.push_back(strs[i]);
        //             for(int j=i+1;j<strs.size();j++)
        //             {
        //                 if( !visited[j] && mp[strs[i]] == mp[strs[j]])
        //                 {
        //                     sub.push_back(strs[j]);
        //                     visited[j]=true;
        //                 }
        //             }
        //             ans.push_back(sub);
        //         }

        //         return ans;
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            string t = s;
            sort(s.begin(), s.end());
            mp[s].push_back(t);
        }
        for (auto it : mp)
            res.push_back(it.second);
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}