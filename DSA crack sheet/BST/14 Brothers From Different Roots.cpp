/*
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.


Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
 

Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1

x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes 2 BST's as parameter in form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106


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
    void inorder(Node *root, vector<int> &inodr)
    {
        if (root == NULL)
            return;
        inorder(root->left, inodr);
        inodr.push_back(root->data);
        inorder(root->right, inodr);
    }
    void inorderRev(Node *root, vector<int> &inodr)
    {
        if (root == NULL)
            return;
        inorder(root->right, inodr);
        inodr.push_back(root->data);
        inorder(root->left, inodr);
    }
    int countPairs(Node *root1, Node *root2, int x)
    {
        int c = 0;
        vector<int> in;
        vector<int> rev;
        inorder(root1, in);
        inorder(root2, rev);
        int i = 0;
        int j = rev.size() - 1;
        while (i < in.size() && j >= 0)
        {
            if (rev[j] + in[i] == x)
            {
                c++;
                i++;
                j--;
            }
            else if (in[i] + rev[j] < x)
            {
                i++;
            }
            else if (in[i] + rev[j] > x)
            {
                j--;
            }
        }
        return c;
    }
};
int main()
{
    FAST;

    return 0;
}