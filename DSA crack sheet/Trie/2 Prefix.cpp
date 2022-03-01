/*
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Example 1:

Input:
N = 4
arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation:
z => zebra
dog => dog
duck => du
dove => dov
Example 2:

Input:
N = 3
arr[] =  {"geeksgeeks", "geeksquiz",
                       "geeksforgeeks"};
Output: geeksg geeksq geeksf
Explanation:
geeksgeeks => geeksg
geeksquiz => geeksq
geeksforgeeks => geeksf
Your task:
You don't have to read input or print anything. Your task is to complete the function findPrefixes() which takes the array of strings and it's size N as input and returns a list of shortest unique prefix for each word

Expected Time Complexity: O(N*length of each word)
Expected Auxiliary Space: O(N*length of each word)

Constraints:
1 ≤ N, Length of each word ≤ 1000

*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct TrieNode
{
    int count;
    TrieNode *child[26];
    TrieNode()
    {
        count = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};
class Solution
{
public:
    TrieNode *root = new TrieNode();

    vector<string> findPrefixes(string arr[], int n)
    {
        vector<string> vec;

        for (int i = 0; i < n; i++)
        {
            maketree(arr[i], root);
        }

        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            TrieNode *curr = root;
            string ans = "";
            for (int j = 0; j < s.length(); j++)
            {
                int ind = s[j] - 'a';
                curr = curr->child[ind];
                if (curr->count == 1)
                {
                    vec.push_back(s.substr(0, j + 1));
                    break;
                }
            }
        }
        return vec;
    }

    void maketree(string s, TrieNode *root)
    {
        TrieNode *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr->child[s[i] - 'a'] == NULL)
            {
                curr->child[s[i] - 'a'] = new TrieNode();
            }
            curr->child[s[i] - 'a']->count++;
            curr = curr->child[s[i] - 'a'];
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends