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
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// 4 1 2 3  5 6 7
int constructBST(vector<int> preorder, int n, int pos, Node *curr, int min, int max)
{
    if (pos >= n || preorder[pos] < min || preorder[pos] > max)
        return pos;
    if (preorder[pos] < curr->data)
    {
        curr->left = new Node(preorder[pos]);
        pos += 1;
        pos = constructBST(preorder, n, pos, curr->left, min, curr->data - 1);
    }
    if (pos == n || preorder[pos] < min || preorder[pos] > max)
        return pos;
    curr->right = new Node(preorder[pos]);
    pos += 1;
    pos = constructBST(preorder, n, pos, curr->right, curr->data + 1, max);
    return pos;
}
Node *preOrderToBST(vector<int> preorder)
{
    int n = preorder.size();
    if (n == 0)
        return NULL;
    Node *root = new Node(preorder[0]);
    if (n == 1)
        return root;
    constructBST(preorder, n, 1, root, INT_MIN, INT_MAX);
    return root;
}
int main()
{
    FAST;

    return 0;
}