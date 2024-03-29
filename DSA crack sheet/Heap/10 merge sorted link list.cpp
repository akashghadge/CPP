#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// C++ implementation to merge k
// sorted linked lists
// | Using MIN HEAP method
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Utility function to create a new node
struct Node *newNode(int data)
{
    // allocate node
    struct Node *new_node = new Node();

    // put in the data
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// 'compare' function used to build up the
// priority queue
struct compare
{
    bool operator()(
        struct Node *a, struct Node *b)
    {
        return a->data > b->data;
    }
};

// function to merge k sorted linked lists
struct Node *mergeKSortedLists(
    struct Node *arr[], int k)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

    // Handles the case when k = 0
    // or lists have no elements in them
    if (pq.empty())
        return NULL;

    struct Node *dummy = newNode(0);
    struct Node *last = dummy;

    // loop till 'pq' is not empty
    while (!pq.empty())
    {

        // get the top element of 'pq'
        struct Node *curr = pq.top();
        pq.pop();

        // add the top element of 'pq'
        // to the resultant merged list
        last->next = curr;
        last = last->next;

        // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }

    // address of head node of the required merged list
    return dummy->next;
}

// function to print the singly linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node *arr[k];

    // creating k = 3 sorted lists
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // merge the k sorted lists
    struct Node *head = mergeKSortedLists(arr, k);

    // print the merged list
    printList(head);

    return 0;
}
