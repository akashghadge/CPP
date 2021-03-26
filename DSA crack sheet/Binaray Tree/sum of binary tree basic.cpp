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

// basically write program to get sum of fulll tree

int sumOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data + sumOfTree(root->leftNode) + sumOfTree(root->righNode);
    return sum;
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Original Tree :" << endl;
    display(root);
    // cout << "height of tree is : " << height(root) << endl;
    cout << "Sum Of tree :" << sumOfTree(root) << endl;
}