// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
    struct Node
    {
        bool is_word{false};
        array<Node *, 26> children;
        Node()
        {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Node trie;

    void insert(Node *node, string w)
    {
        for (auto c : w)
        {
            int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new Node;
            node = node->children[i];
        }
        node->is_word = true;
    }

    Node *follow(Node *node, char c)
    {
        int i = c - 'a';
        return node->children[i];
    }

public:
    // A : given string to search
    // B : vector of available strings
    vector<int> dp;
    void solve(string &A, int i)
    {
        if (i >= A.size())
        {
            dp[i] = 1;
            return;
        }
        Node *node = &trie;
        for (int j = i; j < A.size(); j++)
        {
            node = follow(node, A[j]);
            if (!node)
            {
                return;
            }
            if (node->is_word && dp[j + 1])
            {
                dp[i] = 1;
                return;
            }
        }
    }
    int wordBreak(string A, vector<string> &B)
    {
        // code here
        for (auto &s : B)
            insert(&trie, s);

        for (int i = 0; i <= A.size(); i++)
            dp.push_back(0);

        for (int i = A.size(); i >= 0; i--)
            solve(A, i);

        return dp[0];
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
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends