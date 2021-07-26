/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.


Example 1:

Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear 
first and 2,4,6 are the even numbers that appear later.

Example 2:

Input:
N = 4
Link List = 1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 10000 


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
class Solution
{
public:
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
    Node *createNode(int val)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    Node *divide(int N, Node *head)
    {
        // code here
        Node *temp = head;
        Node *odd = NULL;
        Node *tempOdd = NULL;
        Node *even = NULL;
        Node *tempEven = NULL;
        while (temp != NULL)
        {
            int val = temp->data;
            if ((val % 2) != 0)
            {
                if (!odd)
                {
                    odd = createNode(val);
                    tempOdd = odd;
                }
                else
                {
                    Node *newNode = createNode(val);
                    tempOdd->next = newNode;
                    tempOdd = newNode;
                }
            }
            else
            {
                if (!even)
                {
                    even = createNode(val);
                    tempEven = even;
                }
                else
                {
                    Node *newNode = createNode(val);
                    tempEven->next = newNode;
                    tempEven = newNode;
                }
            }
            temp = temp->next;
        }
        if (!odd)
            return even;
        if (!even)
            return odd;
        tempEven->next = odd;
        return even;
    }
};
int main()
{
    FAST;

    return 0;
}