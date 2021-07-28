/*
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List strating from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3

Your Task:  
You dont need to read input or print anything. Complete the function convertToDLL() which takes root of the given tree as input parameter and returns the head of the doubly link list.

Note:
The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^4


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
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// return the head of the DLL and remove those node from the tree as well.
Node *util(Node *root, Node **headRef)
{
    if (!root)
    {
        return NULL;
    }
    if (!root->left && !root->right)
    {
        root->right = *headRef;

        // Change left pointer of previous head
        if (*headRef != NULL)
            (*headRef)->left = root;

        // Change head of linked list
        *headRef = root;

        return NULL; // Return new root
    }
    root->right = util(root->right, headRef);
    root->left = util(root->left, headRef);
    return root;
}
Node *convertToDLL(Node *root)
{
    // add code here.
    Node *head = NULL;
    util(root, &head);
    return head;
}
int main()
{
    FAST;

    return 0;
}