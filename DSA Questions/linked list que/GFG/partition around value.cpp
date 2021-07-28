/*
Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.
 
Example 1:
Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5
Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.
Example 2:
Input:
1->4->2->10 
x = 3
Output: 
1->2->4->10
Explanation:
Nodes with value less than 3 come first,
then equal to 3 and then greater than 3.
Your task:
You don't need to read input or print anything. Your task is to complete the function partition() which takes the head of the inked list and an integer x as input, and returns the head of the modified linked list after arranging the values according to x.
 
Expected time complexity : O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 <= N <= 105
1 <= k <= 105

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

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *partition(struct Node *head, int x)
{
    // code here
    Node *newHead = NULL;
    Node *temp = NULL;
    temp = head;
    Node *tempNew = NULL;
    while (temp != NULL)
    {
        int val = temp->data;
        if (val < x)
        {
            if (!newHead)
            {
                newHead = new Node(val);
                tempNew = newHead;
            }
            else
            {
                Node *newNode = new Node(val);
                tempNew->next = newNode;
                tempNew = newNode;
            }
        }
        temp = temp->next;
    }
    temp = newHead;
    temp = head;
    while (temp != NULL)
    {
        int val = temp->data;
        if (val == x)
        {
            if (!newHead)
            {
                newHead = new Node(val);
                tempNew = newHead;
            }
            else
            {
                Node *newNode = new Node(val);
                tempNew->next = newNode;
                tempNew = newNode;
            }
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        int val = temp->data;
        if (val > x)
        {
            if (!newHead)
            {
                newHead = new Node(val);
                tempNew = newHead;
            }
            else
            {
                Node *newNode = new Node(val);
                tempNew->next = newNode;
                tempNew = newNode;
            }
        }
        temp = temp->next;
    }
    return newHead;
}
int main()
{
    FAST;

    return 0;
}