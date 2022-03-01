/*
Trie data structure can be used for a more efficient solution. Insert the sorted order of each word in the trie. Since all the anagrams will end at the same leaf node. We can start a linked list at the leaf nodes where each node represents the index of the original array of words. Finally, traverse the Trie. While traversing the Trie, traverse each linked list one line at a time. Following are the detailed steps.
1) Create an empty Trie 
2) One by one take all words of input sequence. Do following for each word 
…a) Copy the word to a buffer. 
…b) Sort the buffer 
…c) Insert the sorted buffer and index of this word to Trie. Each leaf node of Trie is head of a Index list. The Index list stores index of words in original sequence. If sorted buffer is already present, we insert index of this word to the index list. 
3) Traverse Trie. While traversing, if you reach a leaf node, traverse the index list. And print all words using the index obtained from Index list. 


*/
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    struct Node
    {
        Node *links[26] = {nullptr};
        string str = {""};

        bool containsKey(char ch)
        {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node *node)
        {
            links[ch - 'a'] = node;
        }

        Node *getKey(char ch)
        {
            return links[ch - 'a'];
        }

        void setStr(string s)
        {
            str = s;
        }

        string getStr()
        {
            return str;
        }
    };

    class trie
    {
    private:
        Node *root;

    public:
        trie()
        {
            root = new Node();
        }

        void insert(string word, string str)
        {
            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (!node->containsKey(word[i]))
                {
                    node->put(word[i], new Node());
                }
                node = node->getKey(word[i]);
            }
            node->setStr(str);
        }

        string search(string word)
        {
            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {
                if (!node->containsKey(word[i]))
                {
                    return "";
                }
                node = node->getKey(word[i]);
            }
            return node->getStr();
        }
    };

    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        trie tri;
        unordered_map<string, vector<string>> mp;

        set<string> st;

        for (auto str : string_list)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            string s = tri.search(temp);
            if (s == "")
            {
                tri.insert(temp, str);
                st.insert(str);
            }
            else
            {
                mp[s].push_back(str);
                auto it = st.find(s);
                if (it != st.end())
                    st.erase(it);
            }
        }

        vector<vector<string>> ans;

        for (auto p : mp)
        {
            vector<string> v;
            v.push_back(p.first);
            for (auto str : p.second)
            {
                v.push_back(str);
            }
            ans.push_back(v);
        }

        set<string>::iterator iter;
        for (iter = st.begin(); iter != st.end(); iter++)
        {
            ans.push_back(vector<string>{*iter});
        }

        sort(ans.begin(), ans.end());

        return (ans);
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends