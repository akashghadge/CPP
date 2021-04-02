#include <iostream>
using namespace std;
#include <unordered_map>
#include "string"
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
int max(int a, int b)
{
    return a > b ? a : b;
}
/*You are required to complete this method*/
bool solve(Node *root, int *maxHeight, int h)
{
    if (root == NULL)
    {
        return true;
    }
    if (!root->leftNode && !root->righNode)
    {
        if (*maxHeight == 0)
        {
            *maxHeight = h;
            return true;
        }
        return (*maxHeight == h);
    }
    return solve(root->leftNode, maxHeight, h + 1) &&
           solve(root->righNode, maxHeight, h + 1);
}
bool check(Node *root)
{
    int maxHeight = 0;
    return solve(root, &maxHeight, 0);
}
int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Original Tree :" << endl;
    display(root);
}