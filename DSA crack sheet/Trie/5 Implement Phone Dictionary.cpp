/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input:
n = 3
contact[] = {"geeikistest", "geeksforgeeks",
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on
contact list for "g" we get: "geeikistest",
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0".
No results found for "geeips", so print "0".
Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6


*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef struct Node
{
    Node *arr[26];
    bool flag;
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            arr[i] = NULL;
        }
        flag = false;
    }
} Node;

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (!node->arr[idx])
            {
                node->arr[idx] = new Node();
            }
            node = node->arr[idx];
        }
        node->flag = true;
    }

    void dfs(Node *node, string interim, vector<string> &res)
    {
        if (node->flag == true)
        {
            res.push_back(interim);
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->arr[i])
            {
                string temp = interim + (char)(i + 'a');
                dfs(node->arr[i], temp, res);
            }
        }
    }

    vector<string> prefixGenerate(string word)
    {
        Node *node = root;
        vector<string> res;
        string interim = "";
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            int index = word[i] - 'a';
            if (!node->arr[index])
            {
                res.push_back("0");
                return res;
            }
            interim += word[i];
            node = node->arr[index];
        }
        dfs(node, interim, res);
        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie t;
        vector<vector<string>> res;
        sort(contact, contact + n);
        for (int i = 0; i < n; i++)
        {
            t.insert(contact[i]);
        }
        for (int len = 1; len <= s.length(); len++)
        {
            string temp = s.substr(0, len);
            res.push_back(t.prefixGenerate(temp));
        }
        return res;
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
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends