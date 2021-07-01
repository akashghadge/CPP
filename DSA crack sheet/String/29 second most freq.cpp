/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array.


Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).


Constraints:
1<=N<=103


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
Store the frequency of all the strings in a hash map. Check the second highest of all the freuqencies. Then, traverse the hash map and find the string with that frequency (here, we use the fact that there's only one string with second highest frequency).
*/
class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        //code here.
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        vector<int> vec;
        for (auto val : mp)
        {
            vec.push_back(val.second);
        }
        sort(vec.begin(), vec.end());
        int freqNeed = vec[vec.size() - 2];
        for (auto val : mp)
        {
            if (val.second == freqNeed)
            {
                return val.first;
            }
        }
        return "";
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}