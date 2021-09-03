/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105
 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.


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
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    struct Node
    {
        int data;
        Node *right;
        Node *left;
    };

    vector<int> topView(Node *root)
    {
        vector<int> res;
        //Your code here
        if (root == NULL)
        {
            return res;
        }

        // make map for storing if vertically element is printed or not and and queue for Node * and vertical distance
        map<int, int> m;
        queue<pair<Node *, int>> q;
        // push first pair so q.is not empty any way
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            // get first element of queue
            pair<Node *, int> pairCurr = q.front();
            Node *curr = pairCurr.first;
            int val = pairCurr.second;
            q.pop();
            // find there is previos element on that vertical position
            if (m.find(val) == m.end())
            {
                // if have print it
                // res.push_back(curr->data);
                m[val] = curr->data;
            }
            if (curr->left)
            {
                q.push(make_pair(curr->left, val - 1));
            }
            if (curr->right)
            {
                q.push(make_pair(curr->right, val + 1));
            }
        }
        for (auto i = m.begin(); i != m.end(); i++)
            res.push_back(i->second);
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}