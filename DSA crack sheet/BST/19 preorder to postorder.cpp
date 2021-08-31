/*
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104


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
//Function that constructs BST from its preorder traversal.
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
Node *helper(int pre[], int *ptr, int size, int key, int min, int max)
{
    if (*ptr >= size)
        return NULL;
    Node *root = NULL;
    if (min < key && key < max)
    {
        root = new Node(key);
        *ptr = *ptr + 1;
        if (*ptr < size)
        {
            root->left = helper(pre, ptr, size, pre[*ptr], min, key);
        }
        if (*ptr < size)
        {
            root->right = helper(pre, ptr, size, pre[*ptr], key, max);
        }
    }
    return root;
}
Node *constructTree(int pre[], int size)
{
    //code here
    int ptr = 0;
    return helper(pre, &ptr, size, pre[ptr], INT_MIN, INT_MAX);
}
int main()
{
    FAST;

    return 0;
}