/*
Given a Binary Tree, find the maximum sum path from a leaf to root.


Example 1:

Input:
        1
       / \
      2   3 
Output:
4
Explanation: 
Following the path 3 -> 1, results in a
sum of 4, which is the maximum path sum
from leaf to root for the given tree.
Example 2:

Input:
       10
      /  \
    -2    7
    / \   
   8  -4    
Output:
17
Explanation : 
Following the path 7 -> 10, results in a
sum of 17, which is the maximum path sum
from leaf to root for the given tree.

Your task :
You don't need to read input or print anything. Your task is to complete the function maxPathSum() which takes the root node of the tree as input and returns an integer denoting the maximum possible leaf to root path sum.

Expected Time Complexity: O(n) , where n = number of nodes
Expected Auxiliary Space: O(1)

Constraints : 
1 <= Number of nodes <= 10^5

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
class Solution
{
public:
    struct Node
    {
        int data;
        Node *right;
        Node *left;
    };

    int helper(Node *root, int sum, int *m)
    {
        if (root == NULL)
        {
            return 0;
        }
        sum += root->data;
        if (!root->left && !root->right)
        {
            *m = max(sum, *m);
        }
        helper(root->left, sum, m);
        helper(root->right, sum, m);
    }
    int maxPathSum(Node *root)
    {
        //code here
        if (root == NULL)
            return 0;
        int m = 0;
        helper(root, 0, &m);
        return m;
    }
};
int main()
{
    FAST;

    return 0;
}