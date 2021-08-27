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
    Node(int newData)
    {
        data = newData;
        left = right = NULL;
    }
};
/* 


*/
Node *findLCA(Node *root, Node *n1, Node *n2)
{
    if (root == NULL)
        return NULL;
    // any of one node is encounter return it
    if (root->data == n1->data || root->data == n2->data)
        return root;
    // if note there then find left and right subtree
    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
    // if both lca_left and right present then return it
    if (left_lca && right_lca)
        return root;
    // if only one present then return it
    return (left_lca != NULL) ? left_lca : right_lca;
}
Node *findLCAUsingBST(Node *root, Node *n1, Node *n2)
{
    int d = root->data;
    if (d < n1->data && d < n2->data)
        return findLCAUsingBST(root->right, n1, n2);
    else if (d > n1->data && d > n2->data)
        return findLCAUsingBST(root->left, n1, n2);
    else
        return root;
}
int main()
{
    FAST;

    return 0;
}