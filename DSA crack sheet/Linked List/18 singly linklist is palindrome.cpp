/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105


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
bool helper(Node *ptr1, Node *ptr2)
{
    while (ptr1 && ptr2)
    {
        if (ptr1->data != ptr2->data)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}
bool isPalindrome(Node *head)
{
    //Your code here
    if (!head)
        return false;
    if (!head->next)
        return true;
    Node *fast = head;
    Node *slow = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next != NULL)
        fast = fast->next;
    slow->next = rev(slow->next);
    return helper(head, slow->next);
}
int main()
{
    FAST;

    return 0;
}