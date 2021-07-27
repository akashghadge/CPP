/*

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
};
Node *createNode(int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
Node *getMiddle(Node *head, Node *tail)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *a, Node *b)
{
    Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return (result);
}
Node *mergeSortMain(Node *head, Node *tail)
{
    if (tail == head)
    {
        Node *nList = createNode(head->data);
        return nList;
    }
    Node *middleNode = getMiddle(head, tail);
    Node *list1 = mergeSortMain(head, middleNode);
    Node *list2 = mergeSortMain(middleNode, tail);
    return merge(list1, list2);
}
Node *mergeSort(Node *head)
{
    // your code here
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return mergeSortMain(head, tail);
}
Node *merge(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
Node *mergeSort(Node *head)
{
    // your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = slow->next;
    slow->next = NULL;

    return merge(mergeSort(head), mergeSort(newHead));
}

;
int main()
{
    FAST;

    return 0;
}