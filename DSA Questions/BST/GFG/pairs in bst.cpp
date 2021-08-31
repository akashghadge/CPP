/*
Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1 
Explanation: 
Nodes with value 2 and 3 sum up to 5.
Example 2:

Input:
           6
          /    
         5     
        /
       3 
     /  \
    1    4
sum = 2
Output: 0 
Explanation: 
There's no pair that sums up to 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isPairPresent() that takes a root node and a target value as a parameter and returns 1 if there's a pair of Nodes in the BST with values summing up to the target sum, else returns 0. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of Nodes ≤ 105
1 ≤ Sum ≤ 106


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
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        //add code here.
        // Create two stacks. s1 is used for
        // normal inorder traversal and s2 is
        // used for reverse inorder traversal
        // Stack* s1 = createStack(MAX_SIZE);
        // Stack* s2 = createStack(MAX_SIZE);
        stack<Node *> s1;
        stack<Node *> s2;
        int c = 0;
        // Note the sizes of stacks is MAX_SIZE,
        // we can find the tree size and fix stack size
        // as O(Logn) for balanced trees like AVL and Red Black
        // tree. We have used MAX_SIZE to keep the code simple

        // done1, val1 and curr1 are used for
        // normal inorder traversal using s1
        // done2, val2 and curr2 are used for
        // reverse inorder traversal using s2
        bool done1 = false, done2 = false;
        int val1 = 0, val2 = 0;
        Node *curr1 = root;
        Node *curr2 = root;

        // The loop will break when we either find a pair or one of the two
        // traversals is complete
        while (1)
        {
            // Find next node in normal Inorder
            // traversal. See following post
            // https:// www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
            while (done1 == false)
            {
                if (curr1 != NULL)
                {
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                else
                {
                    if (s1.empty())
                        done1 = 1;
                    else
                    {
                        curr1 = s1.top();
                        s1.pop();
                        val1 = curr1->data;
                        curr1 = curr1->right;
                        done1 = 1;
                    }
                }
            }

            // Find next node in REVERSE Inorder traversal. The only
            // difference between above and below loop is, in below loop
            // right subtree is traversed before left subtree
            while (done2 == false)
            {
                if (curr2 != NULL)
                {
                    s2.push(curr2);
                    curr2 = curr2->right;
                }
                else
                {
                    if (s2.empty())
                        done2 = 1;
                    else
                    {
                        curr2 = s2.top();
                        s2.pop();
                        val2 = curr2->data;
                        curr2 = curr2->left;
                        done2 = 1;
                    }
                }
            }

            // If we find a pair, then print the pair and return. The first
            // condition makes sure that two same values are not added
            if ((val1 != val2) && (val1 + val2) == target)
            {
                c++;
                done1 = false;
                done2 = false;
                // return true;
            }

            // If sum of current values is smaller,
            // then move to next node in
            // normal inorder traversal
            else if ((val1 + val2) < target)
                done1 = false;

            // If sum of current values is greater,
            // then move to next node in
            // reverse inorder traversal
            else if ((val1 + val2) > target)
                done2 = false;

            // If any of the inorder traversals is
            // over, then there is no pair
            // so return false
            if (val1 >= val2)
                break;
        }
        return c;
    }
};
int main()
{
    FAST;

    return 0;
}