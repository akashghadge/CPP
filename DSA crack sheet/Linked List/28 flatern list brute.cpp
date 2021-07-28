/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

 

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103


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
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of 
    the flattened linked list. */
Node *getAllData(Node *root, vector<int> &res)
{
    if (!root)
    {
        return NULL;
    }
    res.push_back(root->data);
    getAllData(root->next, res);
    getAllData(root->bottom, res);
    return NULL;
}
Node *createNode(int val)
{
    Node *newNode = new Node(val);
    return newNode;
}
Node *newList(vector<int> &res)
{
    if (res.size() == 0)
        return NULL;
    Node *head = NULL;
    Node *temp = head;
    head = createNode(res[0]);
    temp = head;
    for (int i = 1; i < res.size(); i++)
    {
        Node *newnode = createNode(res[i]);
        temp->bottom = newnode;
        temp = newnode;
    }
    return head;
}
Node *flatten(Node *root)
{
    // Your code here
    vector<int> res;
    getAllData(root, res);
    sort(res.begin(), res.end());
    root = newList(res);
    return root;
}
int main()
{
    FAST;

    return 0;
}