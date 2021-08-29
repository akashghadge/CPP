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
void inorder(Node *root, vector<int> &inodr)
{
    if (root == NULL)
        return;
    inorder(root->left, inodr);
    inodr.push_back(root->data);
    inorder(root->right, inodr);
}
Node *helper(vector<int> &inodr, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (high - low) / 2 + low;
    Node *root = new Node(inodr[mid]);
    root->left = helper(inodr, low, mid - 1);
    root->right = helper(inodr, mid + 1, high);
    return root;
}
/*
        3
    2
1
*/
Node *BSTToBalanced(Node *root)
{
    vector<int> inodr;
    inorder(root, inodr);
    int high = inodr.size();
    int low = 0;
    return helper(inodr, low, high);
}
int main()
{
    FAST;

    return 0;
}