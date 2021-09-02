/*
Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.

Example 1:

Input:
           2
         /    \
        1      6
              /  \
             3    7
Output: 18 16 13 7 0
Explanation:
Every node is replaced with the 
sum of nodes greater than itself. 
The resultant tree is:
               16
             /    \
           18       7
                  /   \
                 13    0
Example 2:

Input:
          2
         /
        1
Output: 2 0
Explanation:
The resultant tree is :
             0
            /
          2
Your task :
You don't have to read input or print anything. Your task is to complete the function transformTree() which takes the root of the tree as input and transforms the BST to a greater sum tree.
Note : The driver code prints the inorder traversal of the transformed BST.
 
Expected Time Complexity: O(N), N = number of nodes
Expected Auxiliary Space: O(N), N = number of nodes
 
Constraints :
1 ≤ N ≤ 104

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
    struct Node *left, *right;
};

class Solution
{
public:
    int sum = 0;
    void helper(struct Node *root)
    {
        if (root == NULL)
            return;
        helper(root->right);
        int temp = root->data;
        root->data = sum;
        sum += temp;
        helper(root->left);
    }
    void transformTree(struct Node *root)
    {
        //code here
        helper(root);
    }
};
int main()
{
    FAST;

    return 0;
}