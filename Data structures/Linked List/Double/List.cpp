/*

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
class List
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    int size;

public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
        size = 0;
    };
    ~List(){};

private:
    Node *createNode(int val)
    {
        Node *newnode = new Node();
        newnode->data = val;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }
    void addNodeFirstTime(int val)
    {
        this->head = createNode(val);
        this->tail = head;
    }

public:
    Node *getHead()
    {
        return this->head;
    }
    int getSize()
    {
        return size;
    }
    void print(bool flag = true)
    {
        if (!head)
            cout << "No list" << en;
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << en;
        if (flag)
        {

            temp = tail;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << en;
        }
    }
    void add(int val)
    {
        if (!this->head)
        {
            addNodeFirstTime(val);
        }
        else
        {
            Node *newnode = createNode(val);
            this->tail->next = newnode;
            newnode->prev = this->tail;
            this->tail = newnode;
        }
        size++;
    }
    void remove()
    {
        if (!head)
            return;
        if (head == tail)
        {
            free(this->head);
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        size--;
    }
    void addFirst(int val)
    {
        if (!this->head)
            addNodeFirstTime(val);
        else
        {
            Node *newnode = createNode(val);
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }
    void removeFirst()
    {
        if (!head)
            return;
        if (head == tail)
        {
            free(this->head);
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        size--;
    }
    void insert(int val, int pos)
    {
        if (pos < 0 || pos > size)
            return;
        else if (pos == 0)
            addFirst(val);
        else if (pos == size)
            add(val);

        else
        {
            int c = 1;
            Node *newNode = createNode(val);
            Node *curr = head;
            while (c < pos)
            {
                c++;
                curr = curr->next;
            }
            newNode->prev = curr;
            newNode->next = curr->next;
            newNode->next->prev = newNode;
            curr->next = newNode;
            size++;
        }
    }
    void del(int pos)
    {
        if (pos < 0 || pos > size - 1)
            return;
        else if (pos == 0)
            removeFirst();
        else if (pos == size - 1)
            remove();
        else
        {
            int c = 0;
            Node *curr = head;
            while (c < pos)
            {
                c++;
                curr = curr->next;
            }
            Node *delHelp = curr;
            Node *temp = curr->next;

            curr->next->prev = curr->prev;
            curr->prev->next = temp;

            free(delHelp);
            size--;
        }
    }
};

int main()
{
    FAST;
    List l;
    for (int i = 0; i < 5; i++)
    {
        l.add(i);
    }
    l.print(false);
    l.del(3);
    l.print(false);
    cout << l.getSize() << en;
    l.del(3);
    l.print(false);
    // l.del(0);
    // l.print();
}