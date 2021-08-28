/*
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input:
    2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node 
with key lesser than the root node’s key and 
the right subtree of root node contains node 
with key greater than the root node’s key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000


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
    Node(int newData)
    {
        data = newData;
        left = right = NULL;
    }
};
class Solution
{
public:
    // int isBSTUtil(Node* root, int min, int max);

    /* Returns true if the given
    tree is a binary search tree
    (efficient version). */
    int isBST(Node *root)
    {
        return (isBSTUtil(root, INT_MIN, INT_MAX));
    }

    /* Returns true if the given
    tree is a BST and its values
    are >= min and <= max. */
    int isBSTUtil(Node *root, int min, int max)
    {
        /* an empty tree is BST */
        if (root == NULL)
            return 1;

        /* false if this Node violates
        the min/max constraint */
        if (root->data < min || root->data > max)
            return 0;

        /* otherwise check the subtrees recursively,
        tightening the min or max constraint */
        return isBSTUtil(root->left, min, root->data - 1) && // Allow only distinct values
               isBSTUtil(root->right, root->data + 1, max);  // Allow only distinct values
    }
};
int main()
{
    FAST;

    return 0;
}