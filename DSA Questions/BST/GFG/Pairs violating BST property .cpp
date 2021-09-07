/*
It is also solved with count inversion property
i.e merge sort
*/

/*
Given a Binary tree and number of nodes in the tree, the task is to find the number of pairs violating the BST property. Binary Search Tree is a node-based binary tree data structure which has the following properties: 

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.
Examples: 

Input: 
         4
       /   \
      5     6
Output: 1
For the above binary tree, pair (5, 4) 
violate the BST property. Thus, count
of pairs violating BST property is 1.

Input:
           50
        /     \
      30        60
     /  \     /    \
   20    25  10     40
Output: 7
For the above binary tree, pairs (20, 10),
(25, 10), (30, 25), (30, 10), (50, 10), 
(50, 40), (60, 40) violate the BST property. 
Thus, count of pairs violating BST property 
is 7.
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
 
Approach: 

Store the inorder traversal of the binary tree in an array.
Now count all the pairs such that a[i] > a[j] for i < j which is number of inversions in the array.
Print the count of pairs violating BST property.
Below is the implementation of the above approach:
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
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */

/*You are required to complete below method */
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
void inorder(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
int missPlace(vector<int> &res)
{
    int c = 0;
    const int M = 1e9 + 7;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = i + 1; j < res.size(); j++)
        {
            if (res[i] >= res[j])
            {
                c = ((c % M) + (1 % M)) % M;
            }
        }
    }
    return c;
}
int pairsViolatingBST(Node *root, int n)
{
    /*Your code here */
    vector<int> res;
    inorder(root, res);
    // printVector(res);
    return missPlace(res);
    // return 0;
}

int main()
{
    FAST;

    return 0;
}