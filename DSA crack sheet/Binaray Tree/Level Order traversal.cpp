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
// level order traversal means pre order traversal
void LevelOrderTraversal(Link root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        LevelOrderTraversal(root->leftNode);
        LevelOrderTraversal(root->righNode);
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    LevelOrderTraversal(root);
}