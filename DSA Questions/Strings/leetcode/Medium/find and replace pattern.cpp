/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
void printVectorMask(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
bool isMatch(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    int i = 0;
    while (i < a.size())
    {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return true;
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    vector<int> mask(pattern.size(), 1);
    int curr = 1;
    char last = pattern[0];
    for (int i = 1; i < pattern.size(); i++)
    {
        if (pattern[i] == last)
        {
            curr++;
            mask[i] = curr;
        }
        else
        {
            curr = 1;
            last = pattern[i];
        }
    }
    // printVectorMask(mask);
    for (string val : words)
    {
        vector<int> maskW(val.size(), 1);
        int currW = 1;
        char lastW = val[0];
        for (int i = 1; i < val.size(); i++)
        {
            if (val[i] == lastW)
            {
                currW++;
                maskW[i] = currW;
            }
            else
            {
                currW = 1;
                lastW = val[i];
            }
        }
        if (isMatch(maskW, mask))
        {
            ans.push_back(val);
        }
    }
    return ans;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> words = {"a", "b", "c"};
    string pattern = "a";
    // vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    // string pattern = "abb";

    words = findAndReplacePattern(words, pattern);
    printVector(words);
    return 0;
}