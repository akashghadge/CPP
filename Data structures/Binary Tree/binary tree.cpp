#include <iostream>
static int count = 0;
using namespace std;
struct node
{
    int data;
    struct node *rightNode;
    struct node *leftNode;
};

typedef struct node *LINK;
LINK root;
LINK createTree();
int displayInorder(struct node *);
int displayPostorder(struct node *);
int displayPreorder(struct node *);
int main()
{
    root = createTree();
    displayPreorder(root);
    // displayInorder(root);
    // displayPostorder(root);
}

LINK createTree()
{
    LINK newnode;
    // cout << "THE VALUE OF THE X IS THE :" << count << endl;
    int x;
    newnode = (LINK)malloc(sizeof(struct node));
    cout << "PLEASE ENTER THE DATA:" << endl;
    cin >> x;

    if (x == 0)
    {
        count--;
        return 0;
    }
    count++;
    newnode->data = x;
    cout << "ENETER THE LEFT CHILD :" << endl;
    newnode->leftNode = createTree();
    cout << "ENETER THE RIGHT CHILD:" << endl;
    newnode->rightNode = createTree();
    return newnode;
}
int displayInorder(LINK root)
{
    LINK tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    displayInorder(tempRoot->leftNode);
    cout << "THE DATA IS THE :" << tempRoot->data << " " << endl;
    displayInorder(tempRoot->rightNode);
}

int displayPostorder(struct node *root)
{
    LINK tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    displayPostorder(tempRoot->leftNode);
    displayPostorder(tempRoot->rightNode);
    cout << "THE DATA IS THE :" << tempRoot->data << endl;
}

int displayPreorder(struct node *root)
{
    LINK tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    cout << "THE DATA IS THE :" << tempRoot->data << endl;
    displayPreorder(tempRoot->leftNode);
    displayPreorder(tempRoot->rightNode);
}