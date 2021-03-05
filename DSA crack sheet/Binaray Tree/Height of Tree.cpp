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
    else
    {
        int lHeight = height(root->leftNode);
        int rHeight = height(root->righNode);
        return max(lHeight, rHeight) + 1;
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    int h = height(root);
    cout << "Height is :" << h << endl;
}