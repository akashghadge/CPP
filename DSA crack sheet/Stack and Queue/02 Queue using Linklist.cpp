#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
template <class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val)
        {
            data = val;
            next = NULL;
        }
    };

    int sizeOfQueue;
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        sizeOfQueue = 0;
    }
    int size()
    {
        return sizeOfQueue;
    }
    void push(T val)
    {
        Node *newnode = new Node(val);
        if (!head)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        sizeOfQueue++;
    }
    bool pop()
    {
        if (sizeOfQueue == 0 && !head)
            return false;
        Node *temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
        }
        free(temp);

        sizeOfQueue--;
        return true;
    }
    bool empty()
    {
        return (head == NULL) ? true : false;
    }
    T front()
    {
        if (!head)
            return -1;
        return head->data;
    }
    T back()
    {
        if (!tail)
            return -1;
        return tail->data;
    }
};
int main()
{
    FAST;
    Queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        cout << q.back() << en;
        q.pop();
    }
    cout << "front :" << en;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        cout << q.front() << en;
        q.pop();
    }

    return 0;
}