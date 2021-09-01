/*
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12
Your Task:
You don't need to read input or print anything. Your task is to complete the function deleteNode() which takes two arguments. The first being the root of the tree, and an integer 'X' denoting the node value to be deleted from the BST. Return the root of the BST after deleting the node with value X. Do not make any update if there's no node with value X present in the BST.

Note: The generated output will be the inorder traversal of the modified tree.
 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
 

Constraints:
1 <= N <= 105


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

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
struct Node *findSucc(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct Node *deleteNode(struct Node *root, int key)
{
    //your code goes here
    if (root == NULL)
        return NULL;
    if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->right && root->left)
        {
            struct Node *succ = findSucc(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
        else if (root->right || root->left)
        {
            return root->right ? root->right : root->left;
        }
        else
        {
            return NULL;
        }
    }
    return root;
}
int main()
{
    FAST;

    return 0;
}