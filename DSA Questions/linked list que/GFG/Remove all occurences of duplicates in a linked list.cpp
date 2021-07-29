/*
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list. 

Example 1:

Input: 
N = 8
Linked List = 23->28->28->35->49->49->53->53
Output: 
23 35
Explanation:
The duplicate numbers are 28, 49 and 53 which 
are removed from the list.
Example 2:

Input:
N = 6
Linked List = 11->11->11->11->75->75
Output: 
Empty list
Explanation:
All the nodes in the linked list have 
duplicates. Hence the resultant list 
would be empty.
Your task:
You don't have to read input or print anything. Your task is to complete the function removeAllDuplicates() which takes the head of the linked list, removes all the occurences of duplicates in the linked list and returns the head of the modified linked list.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 
Constraints:
1 ≤ N ≤ 10^5

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
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    Node *removeAllDuplicates(struct Node *start)
    {
        //code here
        Node *dummy = new Node(0);

        // dummy node points
        // to the original head
        dummy->next = start;

        // Node pointing to last
        // node which has no duplicate.
        Node *prev = dummy;

        // Node used to traverse
        // the linked list.
        Node *current = start;

        while (current != NULL)
        {
            // Until the current and
            // previous values are
            // same, keep updating current
            while (current->next != NULL &&
                   prev->next->data == current->next->data)
                current = current->next;

            // if current has unique value
            // i.e current is not updated,
            // Move the prev pointer to
            // next node
            if (prev->next == current)
                prev = prev->next;

            // when current is updated
            // to the last duplicate
            // value of that segment,
            // make prev the next of current
            else
                prev->next = current->next;

            current = current->next;
        }

        // update original head to
        // the next of dummy node
        start = dummy->next;
    }
};
int main()
{
    FAST;

    return 0;
}