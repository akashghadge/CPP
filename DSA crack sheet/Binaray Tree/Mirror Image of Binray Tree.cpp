#include <iostream>
using namespace std;

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

void Inorder(Link root)
{
    if (root != NULL)
    {
        Inorder(root->leftNode);
        cout << root->data << endl;
        Inorder(root->righNode);
    }
}
Link createNewNode(int val)
{
    Link newNode = (Link)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->leftNode = NULL;
    newNode->righNode = NULL;
    return newNode;
}

// first apporoch link swithiching
Link Mirror(Link root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Link t = root->righNode;
    root->righNode = root->leftNode;
    root->leftNode = t;

    Mirror(root->leftNode);
    Mirror(root->righNode);
    return root;
}

// mirror
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

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Inorder traversal of original" << endl;
    Inorder(root);
    Mirror(root);
    cout << "Inorder Traversal of mirror" << endl;
    Inorder(root);
}