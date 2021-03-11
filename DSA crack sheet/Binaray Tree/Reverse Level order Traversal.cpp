#include <iostream>
using namespace std;
#include "queue"
#include "stack"
// declring structure
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

// reverse level traversal is basically post order traversal of tree
void ReverseOrderTrav(Link root)
{
    queue<Link> q;
    Link curr = root;
    q.push(curr);
    stack<int> out;
    while (!q.empty())
    {
        curr = q.front();
        out.push(curr->data);
        q.pop();
        if (curr->righNode)
        {
            q.push(curr->righNode);
        }
        if (curr->leftNode)
        {
            q.push(curr->leftNode);
        }
    }
    while (!out.empty())
    {
        int data = out.top();
        cout << data << " " << endl;
        out.pop();
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    ReverseOrderTrav(root);
}