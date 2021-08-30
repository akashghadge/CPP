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
    int countPairs(Node *root1, Node *root2, int x)
    {
        // if either of the tree is empty
        if (root1 == NULL || root2 == NULL)
            return 0;

        // stack 'st1' used for the inorder
        // traversal of BST 1
        // stack 'st2' used for the reverse
        // inorder traversal of BST 2
        stack<Node *> st1, st2;
        Node *top1, *top2;

        int count = 0;

        // the loop will break when either of two
        // traversals gets completed
        while (1)
        {

            // to find next node in inorder
            // traversal of BST 1
            while (root1 != NULL)
            {
                st1.push(root1);
                root1 = root1->left;
            }

            // to find next node in reverse
            // inorder traversal of BST 2
            while (root2 != NULL)
            {
                st2.push(root2);
                root2 = root2->right;
            }

            // if either gets empty then corresponding
            // tree traversal is completed
            if (st1.empty() || st2.empty())
                break;

            top1 = st1.top();
            top2 = st2.top();

            // if the sum of the node's is equal to 'x'
            if ((top1->data + top2->data) == x)
            {
                // increment count
                count++;

                // pop nodes from the respective stacks
                st1.pop();
                st2.pop();

                // insert next possible node in the
                // respective stacks
                root1 = top1->right;
                root2 = top2->left;
            }

            // move to next possible node in the
            // inorder traversal of BST 1
            else if ((top1->data + top2->data) < x)
            {
                st1.pop();
                root1 = top1->right;
            }

            // move to next possible node in the
            // reverse inorder traversal of BST 2
            else
            {
                st2.pop();
                root2 = top2->left;
            }
        }

        // required count of pairs
        return count;
    }
};
int main()
{
    FAST;

    return 0;
}