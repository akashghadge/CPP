/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103


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
class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zeros++;
            }
            else if (temp->data == 1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (zeros != 0)
            {
                temp->data = 0;
                zeros--;
            }
            else if (ones != 0)
            {
                temp->data = 1;
                ones--;
            }
            else
            {
                temp->data = 2;
                twos--;
            }
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
    FAST;

    return 0;
}