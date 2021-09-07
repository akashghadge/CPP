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

class Solution
{
public:
    void inorder(Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    void postModify(Node *root, vector<int> &res, int *ptr)
    {
        if (root == NULL)
            return;
        postModify(root->left, res, ptr);
        postModify(root->right, res, ptr);
        root->data = res[*ptr];
        *ptr = *ptr + 1;
        return;
    }
    void convertToMaxHeapUtil(Node *root)
    {
        // Your code goes here
        vector<int> res;
        inorder(root, res);
        int ptr = 0;
        postModify(root, res, &ptr);
    }
};
int main()
{
    FAST;

    return 0;
}