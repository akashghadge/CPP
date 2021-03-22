#include <iostream>
using namespace std;
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
int display(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    display(root->leftNode);
    cout << root->data << " " << endl;
    display(root->righNode);
}

int solve(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    int x = root->data;
    int a = solve(root->leftNode);
    int b = solve(root->righNode);
    root->data = a + b;
    return x + b + a;
}
void sumTree(Link root)
{
    solve(root);
}
int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    display(root);
    sumTree(root);
    display(root);
}