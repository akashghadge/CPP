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

int display_inorderTraversal(Link root)
{
    Link temp = root;
    if (temp == NULL || temp->data == 0)
    {
        return 0;
    }
    display_inorderTraversal(root->leftNode);
    cout << "value : " << root->data << endl;
    display_inorderTraversal(root->righNode);
}
int display_postTraversal(Link root)
{
    Link temp = root;
    if (temp == NULL || temp->data == 0)
    {
        return 0;
    }
    display_inorderTraversal(root->leftNode);
    display_inorderTraversal(root->righNode);
    cout << "value : " << root->data << endl;
}
int display_preorderTraversal(Link root)
{
    Link temp = root;
    if (temp == NULL || temp->data == 0)
    {
        return 0;
    }
    cout << "value : " << root->data << endl;
    display_inorderTraversal(root->leftNode);
    display_inorderTraversal(root->righNode);
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Inorder Traversal" << endl;
    display_inorderTraversal(root);
    cout << "Pre Traversal" << endl;
    display_preorderTraversal(root);
    cout << "post Traversal" << endl;
    display_postTraversal(root);
}
