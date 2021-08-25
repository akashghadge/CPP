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

Node *addNode(Node *root, int val)
{
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (val < root->data)
    {
        root->left = addNode(root->left, val);
    }
    else
    {
        root->right = addNode(root->right, val);
    }
    return root;
}
int main()
{
    FAST;

    return 0;
}