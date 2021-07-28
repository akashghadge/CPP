/*
Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
2
3
1 6 2
4
1 9 3 8

Output:
1 2 6
1 3 8 9

Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.

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
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

//you have to complete this function
node *part(node *head, node *tail)
{
    
}
node *quick(node *head, node *tail)
{
    node *pivot = part(head, tail);
    quick(head, pivot);
    quick(pivot, tail);
}
void quickSort(struct node **headRef)
{
    node *head = *headRef;
    node *tail = *headRef;
    while (!tail->next)
    {
        tail = tail->next;
    }

    *headRef = quick(head, tail);
}
int main()
{
    FAST;

    return 0;
}