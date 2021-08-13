/*

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
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        //code here
        vector<int> res;
        stack<Node *> st;
        // st.push(root);
        Node *curr = root;
        while (!st.empty() || curr != NULL)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                res.push_back(curr->data);
                curr = curr->right;
                // st.pop();
            }
        }
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}