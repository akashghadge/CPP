
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class CircularList
{
public:
    struct Node
    {
        int data;
        Node *next;
    };

private:
    Node *head = NULL;
    Node *ptr = NULL;
    Node *createNode(int nodeData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = nodeData;
        newNode->next = NULL;
        return newNode;
    }

public:
    CircularList()
    {
        head = NULL;
    }
    void initAdd(int val)
    {
        head = createNode(val);
        head->next = head;
        ptr = head;
    }
    void push(int val)
    {
        if (!head)
            return initAdd(val);
        Node *newnode = createNode(val);
        newnode->next = head;
        ptr->next = newnode;
        ptr = newnode;
    }
    bool pop()
    {
        Node *temp = head;
        if (!head || !ptr)
            return false;
        // if list have one element
        else if (head == head->next)
        {
            head = NULL;
            ptr = NULL;
        }
        else
        {
            temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            Node *tempForFree = temp->next;
            temp->next = head;
            free(tempForFree);
        }
    }
    void print()
    {
        if (!head)
            cout << "list is empty" << en;
            
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << en;
    }
};
int main()
{
    FAST;
    CircularList c;
    for (int i = 0; i < 10; i++)
    {
        c.push(i);
    }
    for (int i = 0; i < 10; i++)
    {
        c.pop();
    }

    c.print();
    return 0;
}