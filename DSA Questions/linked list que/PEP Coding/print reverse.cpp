/*
1->2->3->4->5
delete at 2 
1 -> 2  -> 4 -> 5
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
class LinkList
{
private:
    struct node
    {
        int data;
        node *next;
    };
    int sizeOfList;
    node *head;
    node *tail;

    node *createNode(int nodeData)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = nodeData;
        newNode->next = NULL;
        return newNode;
    }

public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
        sizeOfList = 0;
    }
    int size()
    {
        return this->sizeOfList;
    }
    // getter and setter
    node *getHead()
    {
        return this->head;
    }
    node *getTail()
    {
        return this->tail;
    }
    void setHead(node *newHead)
    {
        this->head = newHead;
    }
    void setTail(node *newTail)
    {
        this->tail = newTail;
    }

    // insert
    void push(int val)
    {
        node *newNode = createNode(val);
        if (!head)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->sizeOfList++;
    }
    void pushFront(int val)
    {
        node *newNode = createNode(val);
        newNode->next = head;
        this->head = newNode;
        this->sizeOfList++;
    }
    bool popFront()
    {
        // not created
        if (head == tail and head == NULL)
            return false;
        // only one node
        else if (head->next == NULL && head == tail)
        {
            free(head);
            this->head = NULL;
            this->tail = NULL;
            this->sizeOfList = 0;
        }
        // more than 1
        else
        {
            node *temp = head;
            head = head->next;
            free(temp);
            sizeOfList--;
        }
    }
    bool pop()
    {
        if (!tail)
        {
            return false;
        }
        else if (tail == head)
        {
            this->head = NULL;
            this->tail = NULL;
            this->sizeOfList = 0;
        }
        else
        {
            node *temp = head;
            while (temp->next != this->tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            this->tail = temp;
            this->sizeOfList--;
        }
    }
    bool insert(int position, int val)
    {
        // position not exists
        if (position < 0 or position > sizeOfList)
        {
            return false;
        }
        // first place
        else if (position == 0)
        {
            pushFront(val);
        }
        // last place
        else if (position == sizeOfList)
        {
            push(val);
        }
        // middle
        else
        {
            node *temp = this->head;
            position--;
            while (temp != NULL && position != 0)
            {
                temp = temp->next;
                position--;
            }
            node *nextNode = createNode(val);
            nextNode->next = temp->next;
            temp->next = nextNode;
            sizeOfList++;
        }
        return true;
    }
    bool deleteNode(int position)
    {
        // empty list
        if (head == NULL)
            return false;
        // not preset in list
        else if (position < 0 or position > sizeOfList)
            return false;
        // fornt not
        else if (position == 0)
            popFront();
        else if (position == sizeOfList)
            pop();
        else
        {
            node *temp = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
            }
            node *nextNode = temp->next;
            temp->next = nextNode->next;
            free(nextNode);
            sizeOfList--;
        }
    }
    void reverse()
    {
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;
        tail = head;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void print()
    {
        if (!head)
            cout << "Empty list" << en;
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << en;
    }
    void printRHelp(node *temp)
    {
        if (!temp)
            return;
        printRHelp(temp->next);
        cout << temp->data << " ";
    }
    void printR()
    {
        node *temp = head;
        printRHelp(temp);
        cout << en;
    }
};

int main()
{
    FAST;
    LinkList l;
    for (int i = 0; i < 10; i++)
    {
        l.push(i);
    }
    l.print();
    l.printR();

    return 0;
}