/*
Find the Closest Element in BST 

Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2
Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 0
Explanation: K=9. The node that has
value nearest to K is 9. so the answer
is 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minDiff() that takes the root of the BST and an integer K as its input and returns the minimum absolute difference between any node value of the BST and the integer K.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100000


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
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
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
    int minDiff(Node *root, int k)
    {
        //Your code here
        if (root == NULL)
        {
            return INT_MAX;
        }
        int r = INT_MAX;
        int l = INT_MAX;
        if (root->data < k)
        {
            int diff = abs(root->data - k);
            int recAns = minDiff(root->right, k);
            r = min(diff, recAns);
        }
        else if (root->data > k)
        {
            int diff = abs(root->data - k);
            int recAns = minDiff(root->left, k);
            l = min(diff, recAns);
        }
        else if (root->data == k)
        {
            return 0;
        }
        return min(r, l);
    }
};
int main()
{
    FAST;

    return 0;
}