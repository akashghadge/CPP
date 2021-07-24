/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000


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
int main()
{
	FAST;

	return 0;
}
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
int getCount(Node *head)
{
	Node *temp = head;
	int c = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		c++;
	}
	return c;
}
int intersectionPoint(Node *current1, Node *current2, int d)
{
	for (int i = 0; i < d; i++)
	{
		if (current1 == NULL)
		{
			return -1;
		}
		current1 = current1->next;
	}

	// Move both pointers of both list till they
	// intersect with each other
	while (current1 != NULL && current2 != NULL)
	{
		if (current1 == current2)
			return current1->data;

		// Move both the pointers forward
		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}
int intersectPoint(Node *head1, Node *head2)
{
	// Your Code Here
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d = abs(c1 - c2);
	if (c1 > c2)
	{
		return intersectionPoint(head1, head2, d);
	}
	else
	{
		return intersectionPoint(head2, head1, d);
	}
}
