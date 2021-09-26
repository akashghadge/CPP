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
    int key;
    Node *left;
    Node *right;
};

bool isHeap(struct Node *root)
{
    // your code here
    if (!root)
        return true;
    bool leftAns = isHeap(root->left);
    bool rightAns = isHeap(root->right);
    if (!leftAns && !rightAns)
        return false;
    int lVal = (root->left) ? root->left->key : INT_MIN;
    int rVal = (root->right) ? root->right->key : INT_MIN;
    if (lVal >= root->key || rVal >= root->key)
    {
        return false;
    }
    return true;
}
bool isHeap(struct Node *tree)
{
    // code here
    if (!tree || !tree->left && !tree->right)
        return true;
    if (tree && !tree->left && tree->right)
        return false;
    int l = 0, r = 0;
    if (tree->left)
        l = tree->left->key;
    if (tree->right)
        r = tree->right->key;
    return (l < tree->key && r < tree->key && isHeap(tree->left) && isHeap(tree->right));
}
int main()
{
    FAST;

    return 0;
}