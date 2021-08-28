/*
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
Note: The generated output contains the inorder traversal of the modified tree.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).


Constraints:
1 <= Number of nodes <= 105
1 <= K <= 106
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
//Function to insert a node in a BST.
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
Node *insert(Node *root, int Key)
{
    // Your code here
    if (root == NULL)
    {
        Node *newNode = new Node(Key);
        return newNode;
    }
    else if (root->data > Key)
    {
        root->left = insert(root->left, Key);
    }
    else if (root->data < Key)
    {
        root->right = insert(root->right, Key);
    }
    else if (root->data == Key)
    {
        return root;
    }
}
int main()
{
    FAST;

    return 0;
}