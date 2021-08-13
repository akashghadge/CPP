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
vector<int> postOrder(Node *root)
{
    // code here
    stack<Node *> s;
    vector<int> res;
    // for preorder first push the root node in it so here stack is always not empty
    s.push(root);
    Node *curr = root;

    stack<int> out;
    while (!s.empty())
    {
        // pop elemen and print it
        curr = s.top();
        out.push(curr->data);
        s.pop();
        // here we no need push right first here
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }

    while (!out.empty())
    {
        int data = out.top();
        out.pop();
        res.push_back(data);
    }
    return res;
}
int main()
{
    FAST;

    return 0;
}