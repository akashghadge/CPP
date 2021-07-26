/*
Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 

Note: The output could be large take modulo 109+7.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow, the first line of each test case contains an integer N denoting the size of the first linked list (L1). In the next line are the space separated values of the first linked list. The third line of each test case contains an integer M denoting the size of the second linked list (L2). In the forth line are space separated values of the second linked list.

Output:
For each test case output will be an integer denoting the product of the two linked list.

User Task:
The task is to complete the function multiplyTwoLists() which should multiply the given two linked lists and return the result.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 

Output:
64
1000

Explanation:
Testcase 1: 32*2 = 64.

Testcase 2: 100*10 = 1000.

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

//  Linked list node structure
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
Node *rev(Node *head)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

long long multiplyTwoLists(Node *first, Node *second)
{
    //Your code here
    //   long long M=1e9+7;
    //   long long num1=0;
    //   long long num2=0;
    //   long long i=1;
    //   l1=rev(l1);
    //   l2=rev(l2);
    //   while(l1 != NULL)
    //   {
    //       num1+=(l1->data*1LL*i)%M;
    //       i*=10;
    //       l1=l1->next;

    //   }
    //   i=1;
    //   while(l2 != NULL)
    //   {
    //       num2+=(l2->data * 1LL* i)%M;
    //       i*=10;
    //       l2=l2->next;
    //   }
    //   return ((num1%M)*(num2%M))%M;
    long long N = 1000000007;
    long long num1 = 0, num2 = 0;
    while (first || second)
    {
        if (first)
        {
            num1 = ((num1 % N) * 10) % N + first->data;
            first = first->next;
        }
        if (second)
        {
            num2 = ((num2 % N) * 10) % N + second->data;
            second = second->next;
        }
    }

    return ((num1 % N) * (num2 % N)) % N;
}
int main()
{
    FAST;

    return 0;
}