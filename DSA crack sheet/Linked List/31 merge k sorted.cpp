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

public:
    //Function to merge K sorted linked list.
    void addToQue(priority_queue<int, vector<int>, greater<int>> &pq, Node *head)
    {
        while (head != NULL)
        {
            pq.push(head->data);
            head = head->next;
        }
    }
    Node *createNode(int val)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < K; i++)
        {
            addToQue(pq, arr[i]);
        }
        Node *newList = NULL;
        Node *temp = NULL;
        while (!pq.empty())
        {
            Node *newnode = createNode(pq.top());
            if (!newList)
            {
                newList = newnode;
                temp = newnode;
            }
            else
            {
                temp->next = newnode;
                temp = newnode;
            }
            pq.pop();
        }
        return newList;
    }
};
int main()
{
    FAST;

    return 0;
}