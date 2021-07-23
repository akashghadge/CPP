/*
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
Your Task:
The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000

Company Tags
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
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    Node *res = NULL;
    Node *temp;
    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            if (!res)
            {
                res = new Node(head1->data);
                temp = res;
            }
            else
            {
                struct Node *newNode = new Node(head1->data);
                temp->next = newNode;
                temp = temp->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return res;
}
int main()
{
    FAST;

    return 0;
}