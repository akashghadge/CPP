#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
#include <vector>
#include "stack"
// declring structure
struct Node
{
    int data;
    struct Node *rightNode;
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
    newnode->rightNode = create_bTree();
    return newnode;
}

// isBalanced tree
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->leftNode);
    int rheight = height(root->rightNode);
    return max(lheight, rheight) + 1;
}

int isBalanced(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (height(root->rightNode) - height(root->leftNode));
}
int balanceWraper(Link root)
{
    int i = isBalanced(root);
    if (i == 1 || i == 0 || i == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    int result = balanceWraper(root);
    cout << "Result  : " << result << endl;
}