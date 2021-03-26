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
Link createNewNode(int val)
{
    Link newNode = (Link)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->leftNode = NULL;
    newNode->righNode = NULL;
    return newNode;
}
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
Link MirrorNew(Link root, Link *mirrorRoot)
{
    if (root == NULL)
    {
        return NULL;
    }
    *mirrorRoot = createNewNode(root->data);
    MirrorNew(root->leftNode, &((*mirrorRoot)->righNode));
    MirrorNew(root->righNode, &((*mirrorRoot)->leftNode));
}
int isMirror(Link root1, Link root2)
{
    if (root1->data == root2->data)
    {
        if (isMirror(root1->leftNode, root2->righNode) && isMirror(root1->righNode, root2->leftNode))
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    cout << "Hello Akash" << endl;
    Link root1 = create_bTree();
    Link root2;
    cout << "One tree" << endl;
    display(root1);
    cout << "Second tree" << endl;
    MirrorNew(root1, &root2);
    display(root2);
    int result = isMirror(root1, root1);
    cout << "Result : " << result << endl;
}