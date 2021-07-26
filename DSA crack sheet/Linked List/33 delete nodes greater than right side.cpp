/*
Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 1000
1 ≤ element of linked list ≤ 1000
Note: Try to solve the problem without using any extra space.


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
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *rev(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        // 5 4 3 2 1
        // m 5
        head = rev(head);
        struct Node *current = head;

        /* Initialize max */
        struct Node *maxnode = head;
        struct Node *temp;

        while (current != NULL &&
               current->next != NULL)
        {
            /* If current is smaller than max,
        then delete current */
            if (current->next->data < maxnode->data)
            {
                temp = current->next;
                current->next = temp->next;
                free(temp);
            }

            /* If current is greater than max,
            then update max and move current */
            else
            {
                current = current->next;
                maxnode = current;
            }
        }
        head = rev(head);
        return head;
    }
};
int main()
{
    FAST;

    return 0;
}