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

int getSum(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getSum(root->leftNode) + root->data + getSum(root->righNode);
}

int IsSum(Link root)
{
    if (root == NULL || (root->leftNode == NULL && root->righNode == NULL))
    {
        return 1;
    }
    int ls = getSum(root->leftNode);
    int rs = getSum(root->righNode);
    if ((root->data == ls + rs) && IsSum(root->leftNode) && IsSum(root->righNode))
    {
        return 1;
    }
    return 0;
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
    cout << "Original Tree :" << endl;
    display(root);
    sumTree(root);
    cout << "After converting it to SUM" << endl;
    display(root);
    cout << "Is it is Sum tree :" << IsSum(root) << endl;
}