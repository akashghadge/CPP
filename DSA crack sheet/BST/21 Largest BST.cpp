/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106


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

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct Node *newNode(int data)
    {
        struct Node *node = new Node(0);
        node->data = data;
        node->left = node->right = NULL;

        return (node);
    }

    // Information to be returned by every
    // node in bottom up traversal.
    struct Info
    {
        int sz;  // Size of subtree
        int max; // Min value in subtree
        int min; // Max value in subtree
        int ans; // Size of largest BST which
        // is subtree of current node
        bool isBST; // If subtree is BST
    };

    // Returns Information about subtree. The
    // Information also includes size of largest
    // subtree which is a BST.
    Info largestBSTBT(Node *root)
    {
        // Base cases : When tree is empty or it has
        // one child.
        if (root == NULL)
            return {0, INT_MIN, INT_MAX, 0, true};
        if (root->left == NULL && root->right == NULL)
            return {1, root->data, root->data, 1, true};

        // Recur for left subtree and right subtrees
        Info l = largestBSTBT(root->left);
        Info r = largestBSTBT(root->right);

        // Create a return variable and initialize its
        // size.
        Info ret;
        ret.sz = (1 + l.sz + r.sz);

        // If whole tree rooted under current root is
        // BST.
        if (l.isBST && r.isBST && l.max < root->data &&
            r.min > root->data)
        {
            ret.min = min(l.min, min(r.min, root->data));
            ret.max = max(r.max, max(l.max, root->data));

            // Update answer for tree rooted under
            // current 'root'
            ret.ans = ret.sz;
            ret.isBST = true;

            return ret;
        }

        // If whole tree is not BST, return maximum
        // of left and right subtrees
        ret.ans = max(l.ans, r.ans);
        ret.isBST = false;

        return ret;
    }
    int largestBst(Node *root)
    {
        //Your code here
        return largestBSTBT(root).ans;
    }
};

int main()
{
    FAST;

    return 0;
}