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
// here we use concept of reverse inorder
int sum = 0;
void sumBST(Node *root)
{
    if (root == NULL)
        return;
    sumBST(root->right);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    sumBST(root->left);
}
int main()
{
    FAST;

    return 0;
}