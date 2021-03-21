#include <iostream>
using namespace std;
#include "stack"
// declring structure

struct NodeLink
{
    int data;
    NodeLink *next, *prev;
};
typedef struct NodeLink *LinkDLL;

struct Node
{
    int data;
    struct Node *righNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;
Link create_bTree()
{
    Link newnode = (Link)malloc(sizeof(struct Node));
    cout << "Please enter Data : " << endl;
    int data;
    cin >> data;
    if (data == 0)
    {
        return NULL;
    }
    newnode->data = data;
    cout << "Enter data for Left Child :" << endl;
    newnode->leftNode = create_bTree();
    cout << "Enter data for Right Child :" << endl;
    newnode->righNode = create_bTree();
    return newnode;
}
LinkDLL createNewNodeDLL(int data)
{
    LinkDLL newnode = (LinkDLL)malloc(sizeof(struct NodeLink)); 
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return newnode;
}
LinkDLL binrayToDll(Link root)
{
    Link temp = root;
    stack<Link> s;
    LinkDLL head = NULL;
    LinkDLL tempDLL = NULL;
    LinkDLL prev = NULL;
    while (!s.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->leftNode;
        }
        else
        {
            temp = s.top();
            s.pop();
            if (head == NULL)
            {
                head = createNewNodeDLL(temp->data);
                tempDLL = head;
            }
            else
            {
                LinkDLL newnode = createNewNodeDLL(temp->data);
                tempDLL->next = newnode;
                newnode->prev = tempDLL;
                tempDLL = newnode;
            }

            temp = temp->righNode;
        }
    }
    return head;
}

void display(LinkDLL head)
{
    LinkDLL temp = head;
    cout << "Forword traversal" << endl;

    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
    cout << "Reverse traversal" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    LinkDLL head = binrayToDll(root);
    display(head);
}