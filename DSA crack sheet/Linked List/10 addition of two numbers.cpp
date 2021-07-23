/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000


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
    //Function to add two numbers represented by linked list.
    Node *rev(Node *head)
    {
        Node *curr = head;
        Node *nextNode = head;
        Node *prev = NULL;
        while (nextNode != NULL)
        {
            nextNode = nextNode->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = rev(first);
        second = rev(second);
        struct Node *res = NULL, *temp = NULL;
        int carry = 0;
        while (first != NULL && second != NULL)
        {
            int val = first->data + second->data;
            int curr = (carry + val) % 10;
            carry = (carry + val) / 10;
            if (!res)
            {
                res = new Node(curr);
                temp = res;
            }
            else
            {
                struct Node *newNode = new Node(curr);
                temp->next = newNode;
                temp = temp->next;
            }
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            int val = first->data;
            int curr = (carry + val) % 10;
            carry = (carry + val) / 10;
            if (!res)
            {
                res = new Node(curr);
                temp = res;
            }
            else
            {
                struct Node *newNode = new Node(curr);
                temp->next = newNode;
                temp = temp->next;
            }
            first = first->next;
        }
        while (second != NULL)
        {
            int val = second->data;
            int curr = (carry + val) % 10;
            carry = (carry + val) / 10;
            if (!res)
            {
                res = new Node(curr);
                temp = res;
            }
            else
            {
                struct Node *newNode = new Node(curr);
                temp->next = newNode;
                temp = temp->next;
            }
            second = second->next;
        }
        if (carry > 0)
        {
            struct Node *newNode = new Node(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        res = rev(res);
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}