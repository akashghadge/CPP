/*
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST.

Example 1:

Input:
Range = [-10, 13]
Lightbox
Output:
-8 6 7 13
Explanation:
Nodes with values -13, 14 and 15 are 
outside the given range and hence are 
removed from the BST.

BinaryTreeModified2
This is the resultant BST and it's 
inorder traversal is -8 6 7 13.
Example 2:

Input:
Range = [2, 6]
        14
      /    \
     4      16
    / \     /
   2   8   15
  / \  / \
 -8  3 7  10
Output:
2 3 4
Explanation:
After removing nodes outside the range, 
the resultant BST looks like:
               4
              /
             2
              \
                3 
The inorder traversal of this tree is: 2 3 4
Your task:
You don't have to read input or print anything. Your task is to complete the function removekeys() which takes the root node of the BST and the range as input and returns the root of the modified BST after removing the nodes outside the given range.
 
Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(h)
 
Constraints:
1 ≤ Number of Nodes ≤ 105
1 ≤ K ≤ 105

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
    Node *removekeys(Node *root, int l, int r)
    {
        // code here
        // code here
        if (root == NULL)
            return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l)
        {
            Node *rChild = root->right;
            delete root;
            return rChild;
        }
        else if (root->data > r)
        {
            Node *lChild = root->left;
            delete root;
            return lChild;
        }
        else
        {
            return root;
        }
    }
};
int main()
{
    FAST;

    return 0;
}