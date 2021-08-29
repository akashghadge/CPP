/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)


Constraints:
1 <= N <= 1000
1 <= K <= N


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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void helper(Node *root, int *curr, int k, int *res)
    {
        if (root == NULL)
            return;
        helper(root->right, curr, k, res);
        *curr = *curr + 1;
        if (*curr == k)
        {
            // cout<<"hello"<<endl;
            *res = root->data;
            return;
        }
        helper(root->left, curr, k, res);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int res = 0;
        int curr = 0;
        helper(root, &curr, K, &res);
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}