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
class Stack
{
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

    int sizeOfStack;
    Node *head;

public:
    Stack()
    {
        sizeOfStack = 0;
        head = NULL;
    }
    int size()
    {
        return sizeOfStack;
    }
    void push(T val)
    {
        Node *newnode = new Node(val);
        if (!head)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        sizeOfStack++;
    }
    bool pop()
    {
        if (!head)
            return false;
        Node *temp = head;
        head = head->next;
        free(temp);
        sizeOfStack--;
        return true;
    }
    bool empty()
    {
        return (head) ? false : true;
    }
    T top()
    {
        return head->data;
    }
};
int main()
{
    FAST;
    Stack<int> st;
    for (int i = 0; i < 10; i++)
    {
        st.push(i);
    }
    cout << "size :" << st.size() << en;

    while (!st.empty())
    {
        cout << st.top() << en;
        st.pop();
    }
    cout << "size :" << st.size() << en;

    return 0;
}