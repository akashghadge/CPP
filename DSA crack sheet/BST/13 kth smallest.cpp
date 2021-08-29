/*
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2
Example 2:

Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=100000


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
    // Return the Kth smallest element in the given BST
    void helper(Node *root, int *curr, int k, int *res)
    {
        if (root == NULL)
            return;
        helper(root->left, curr, k, res);
        *curr = *curr + 1;
        if (*curr == k)
        {
            *res = root->data;
            return;
        }
        helper(root->right, curr, k, res);
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        int curr = 0;
        int res = -1;
        helper(root, &curr, K, &res);
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}