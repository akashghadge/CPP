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
int max(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
Node *find(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    else if (val < root->data)
        return find(root->left, val);
    else if (val > root->data)
        return find(root->right, val);
    else
        return root;
}
int size(Node *root, int *s)
{
    if (root == NULL)
        return 0;
    *s++;
    size(root->left, s);
    size(root->right, s);
}
int sum(Node *root, int *s)
{
    if (root == NULL)
        return 0;
    *s += root->data;
    size(root->left, s);
    size(root->right, s);
}
int main()
{
    FAST;

    return 0;
}