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

void printRange(Node *root, int lb, int ub)
{
    if (root == NULL)
        return;
    printRange(root->left, lb, ub);
    (lb <= root->data && root->data <= ub) ? cout << root->data << " " << en : cout << "";
    printRange(root->right, lb, ub);
}

void optimise(Node *root, int lb, int ub)
{
    if (root == NULL)
        return;
    else if (root->data > lb && root->data < ub)
    {
        optimise(root->left, lb, ub);
        cout << root->data << " ";
        optimise(root->right, lb, ub);
    }
    else if (root->data > lb && root->data > ub)
        optimise(root->left, lb, ub);
    else if (root->data < lb && root->data < ub)
        optimise(root->right, lb, ub);
}
int main()
{
    FAST;

    return 0;
}