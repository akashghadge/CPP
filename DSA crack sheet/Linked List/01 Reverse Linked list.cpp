#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class LinkedList
{
public:
    struct Node
    {
        int data;
        Node *next;
    };

private:
    Node *head = NULL;
    Node *tail = NULL;
    Node *createNode(int nodeData)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = nodeData;
        newNode->next = NULL;
        return newNode;
    }

public:
    Node *createNewLinkedList(int value)
    {
        if (head)
        {
            return NULL;
        }
        Node *newNode = createNode(value);
        this->head = newNode;
        this->tail = newNode;
        return newNode;
    }
    bool insertNode(int insertedData)
    {
        if (!head)
        {
            createNewLinkedList(insertedData);
            return true;
        }
        Node *newNode = createNode(insertedData);
        tail->next = newNode;
        tail = newNode;
        return true;
    }
    Node *getHead()
    {
        return this->head;
    }
    Node *setHead(Node *newHead)
    {
        this->head = newHead;
        return newHead;
    }
    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << en;
    }
};

typedef LinkedList::Node Node;
Node *revItr(Node *head)
{
    Node *curr = head;
    Node *nextNode = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
/*
1->2->3->4->5

*/
Node *util(Node *prev, Node *curr)
{
    if (!curr)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return util(curr, next);
}
Node *revRec(Node *head)
{
    return util(NULL, head);
}
void revGroup(Node *head, int start, int end)
{
    int pointer = 1;
    Node *temp = head;
    Node *prev = NULL;
    while (pointer < start && temp)
    {
        prev = temp;
        temp = temp->next;
        pointer++;
    }

    Node *curr = temp;
    Node *nextNode = temp;
    Node *stop_point = curr;
    while (nextNode != NULL && pointer < end)
    {
        nextNode = nextNode->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pointer++;
    }
    stop_point->next->next = curr;
    stop_point->next = prev;
}
int main()
{
    FAST;
    LinkedList l;
    for (int i = 0; i < 10; i++)
    {
        l.insertNode(i);
    }
    Node *temp = l.getHead();
    l.print();
    Node *newHead = revItr(l.getHead());
    l.setHead(newHead);
    // l.print();
    newHead = revRec(l.getHead());
    l.setHead(newHead);
    l.print();
    revGroup(l.getHead(), 4, 6);
    l.print();
    return 0;
}