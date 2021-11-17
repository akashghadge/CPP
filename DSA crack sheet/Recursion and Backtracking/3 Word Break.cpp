/*
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.
Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking 
of the string s where all the words are present 
in dict.
Your Task:
You do not need to read input or print anything. Your task is to complete the function wordBreak() which takes n, dict and s as input parameters and returns a list of possible sentences. If no sentence is possible it returns an empty list.

Expected Time Complexity: O(N2*n) where N = |s|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ n ≤ 20
1 ≤ dict[i] ≤ 15
1 ≤ |s| ≤ 500 


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
void sol(string str, string ans, unordered_map<string, bool> &mp, vector<string> &res)
{
    if (str.size() == 0)
    {
        res.push_back("(" + ans + ")");
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string chunk = str.substr(0, i + 1);
        string rem = str.substr(i + 1);
        if (mp.find(chunk) != mp.end())
        {
            sol(rem, ans + " " + chunk, mp, res);
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    // code here
    unordered_map<string, bool> mp;
    for (auto d : dict)
    {
        mp[d] = true;
    }
    vector<string> res;
    sol(s, "", mp, res);
    return res;
}
int main()
{
    FAST;

    return 0;
}