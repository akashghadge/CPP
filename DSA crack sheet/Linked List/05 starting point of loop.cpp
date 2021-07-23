/*
Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. If the loop is present then it returns point to the first node of the loop. Else it returns NULL.

Example : 

Input : Head of below linked list


Output : Pointer to node 2
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We have discussed Floyd’s loop detection algorithm. Below are steps to find the first node of the loop.
1. If a loop is found, initialize a slow pointer to head, let fast pointer be at its position. 
2. Move both slow and fast pointers one node at a time. 
3. The point at which they meet is the start of the loop.


*/

// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *next;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to detect and remove loop
// in a linked list that may contain loop
Node *detectAndRemoveLoop(Node *head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop does not exist
    if (slow != fast)
        return NULL;

    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

/* Driver program to test above function*/
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node *res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;

    return 0;
}
/*
How does this approach work? 
Let slow and fast meet at some point after Floyd’s Cycle finding algorithm. The below diagram shows the situation when the cycle is found.
 

LinkedListCycle

We can conclude below from the above diagram 

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time
From the above equation, we can conclude below 

    m + k = (x-2y)*n

Which means m+k is a multiple of n.
So if we start moving both pointers again at the same speed such that one pointer (say slow) begins from the head node of the linked list and other pointers (say fast) begins from the meeting point. When the slow pointer reaches the beginning of the loop (has made m steps), the fast pointer would have made also moved m steps as they are now moving the same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No, because the slow pointer enters the cycle first time after m steps.


*/