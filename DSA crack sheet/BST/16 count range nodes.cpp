/*
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range
Example 2:

Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the
given range.
Your Task:
This is a function problem. You don't have to take input. You are required to complete the function getCountOfNode() that takes root, l ,h as parameters and returns the count.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100
1 <= l < h < 103


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
//Function to count number of nodes in BST that lie in the given range.
int helper(Node *root, int l, int h, int *c);
int helperD(Node *root, int l, int h, int *c)
{
    if (root == NULL)
        return 0;
    helperD(root->left, l, h, c);
    if (root->data >= l && root->data <= h)
        *c = *c + 1;
    helperD(root->right, l, h, c);
}
int getCount(Node *root, int l, int h)
{
    // your code goes here
    int c = 0;
    helper(root, l, h, &c);
    return c;
}

int helper(Node *root, int l, int h, int *c)
{
    if (root == NULL)
        return 0;
    if (root->data >= l && root->data <= h)
    {
        *c = *c + 1;
        helper(root->left, l, h, c);
        helper(root->right, l, h, c);
    }
    else if (root->data < l)
    {
        helper(root->right, l, h, c);
    }
    else if (root->data > h)
    {
        helper(root->left, l, h, c);
    }
    else
    {
        return 0;
    }
}
int main()
{
    FAST;

    return 0;
}