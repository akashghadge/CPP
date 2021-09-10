/*
Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. Here P is a given positive integer and is smaller than the count of nodes(N) in a linked list.

Input:
The first line of input contains an integer T denoting the no of test cases. For each test case, the first line of input contains two integers N and P denoting the number of nodes in Linked List and the number of nodes to be rotated respectively.

Output:
For each test case, output the final linked list after the P rotations in it.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= P <= N

Example:
Input: 
1
6 2
1 2 3 4 5 6

Output:
3 4 5 6 1 2

Explanation:
Testcase 1: Doubly linked list after rotating 2 nodes is: 3 4 5 6 1 2.

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

struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct node *update(struct node *head, int p)
{
    //Add your code here
    // int i=1;
    // node * temp=start;
    // while(i<p)
    // {
    //     temp=temp->next;
    //     i++;
    // }
    // node * newhead=temp->next;
    // temp->next->prev=NULL;
    // temp->next=NULL;
    // while(temp->next!=NULL)
    // {
    //     temp=temp->next;
    // }
    // temp->next=start;
    // start->prev=temp;
    // return newhead;
    node *ptr = head;
    node *nptr = head;

    p = p - 1;
    while (p--)
    {
        ptr = ptr->next;
    }

    head = ptr->next;
    head->prev = NULL;
    node *last = ptr;
    ptr = ptr->next;
    last->next = NULL;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = nptr;
    nptr->prev = ptr;

    return head;
}
int main()
{
    FAST;

    return 0;
}