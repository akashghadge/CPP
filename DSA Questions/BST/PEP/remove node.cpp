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
    Node *right;
    Node *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    };
};
int getAndRemoveInorderPredecessor(Node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}
Node *removeNode(Node *root, int val)
{
    // 0 child
    // 1 child
    // 2 child
    if (root->data == val)
    {
        if (!root->left && !root->right)
        {
            return NULL;
        }
        else if (!root->left || !root->right)
        {
            if (root->left)
                return root->left;
            else
                return root->right;
        }
        else
        {
            int predecessor = getAndRemoveInorderPredecessor(root);
            root->data = predecessor;
            root->left = removeNode(root->left, predecessor);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = removeNode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = removeNode(root->right, val);
    }
}
int main()
{
    FAST;

    return 0;
}