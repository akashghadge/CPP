/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.


Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 1000

Company Tags
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
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void helper(Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        helper(root->left, res);
        res.push_back(root->data);
        helper(root->right, res);
    }
    Node *binaryTreeToBST(Node *root)
    {
        //Your code goes here
        vector<int> res;
        helper(root, res);
        sort(res.begin(), res.end());
        Node *org = root;
        org->right = NULL;
        root->data = res[res.size() - 1];
        // cout<<"hello"<<endl;
        int i = res.size() - 2;
        while (i >= 0)
        {
            Node *newNode = new Node(res[i]);
            root->left = newNode;
            root = root->left;
            i--;
        }
        return org;
    }
};
int main()
{
    FAST;

    return 0;
}