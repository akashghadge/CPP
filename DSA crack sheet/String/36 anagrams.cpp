/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
no on
is
Explanation:
There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2. 

Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.


Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.


Constraints:
1<=N<=100


*/
#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
here firstly sort all string and stored sorted strings in hashmap's key and value is vector 
then traverse every key of hash table and then just add
*/
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    // Your Code Here
    // unordered_map<string, vector<int>> mp;
    // vector<string> original = string_list;
    // for (int i = 0; i < string_list.size(); i++)
    // {
    //     sort(string_list[i].begin(), string_list[i].end());
    //     mp[string_list[i]].push_back(i);
    // }
    // vector<vector<string>> ans;
    // for (auto val : mp)
    // {
    //     vector<string> temp;
    //     for (int index : val.second)
    //     {
    //         temp.push_back(original[index]);
    //     }
    //     ans.push_back(temp);
    // }
    // return ans;

    unordered_map<string, vector<string>> mp;
    vector<string> original = string_list;
    for (int i = 0; i < string_list.size(); i++)
    {
        string origin = string_list[i];
        sort(string_list[i].begin(), string_list[i].end());
        mp[string_list[i]].push_back(origin);
    }
    vector<vector<string>> ans;
    for (auto val : mp)
    {
        ans.push_back(val.second);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}