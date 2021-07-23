/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000


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
        struct Node *next;

        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };

    // code heare
    int helper(Node *head)
    {
        if (!head)
            return 1;
        int rres = helper(head->next);
        if (rres == 1)
        {
            int temp = head->data;
            if (temp == 9)
            {
                head->data = 0;
                return 1;
            }
            else
            {
                head->data++;
                return 0;
            }
        }
        else if (rres == 0)
        {
            return 0;
        }
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        int res = helper(head);
        if (res == 1)
        {
            Node *newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }
        return head;
    }
};
int main()
{
    FAST;

    return 0;
}