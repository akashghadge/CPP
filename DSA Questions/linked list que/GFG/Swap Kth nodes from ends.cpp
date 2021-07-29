/*
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

 

Example 1:

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after
swapping the 1st node from the beginning
and end thenew list will be 4 2 3 1.
 

Example 2:

Input:
N = 5,  K = 7
value[] = {1,2,3,4,5}
Output: 1
Explanation: K > N. Swapping is invalid. 
Return the head node as it is.
 

Your Task: 
You do not need to read input or print anything. The task is to complete the function swapkthnode(), which has takes head of link list, N and K as input parameters and returns the new head.
The generated output will be 1 if you are able to complete your task. 

 

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

 

Constraints:
1 <= N <= 103
1 <= K <= 103


*/

// A C++ program to swap Kth node
// from beginning with kth node from end
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    struct Node *next;
};

/* Utility function to insert
a node at the beginning */
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(
        sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Utility function for calculating
length of linked list */
int countNodes(struct Node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}

/* Function for swapping kth nodes
from both ends of linked list */
// code here
void swapKth(struct Node **head_ref, int k)
{
    
}

// Driver program to test above functions
int main()
{
    // Let us create the following
    // linked list for testing
    // 1->2->3->4->5->6->7->8
    struct Node *head = NULL;
    for (int i = 8; i >= 1; i--)
        push(&head, i);

    cout << "Original Linked List: ";
    printList(head);

    for (int k = 1; k < 9; k++)
    {
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }

    return 0;
}
