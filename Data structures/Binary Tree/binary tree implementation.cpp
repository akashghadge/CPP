#include <iostream>
using namespace std;
static int count = 0;
struct node
{
    int data;
    struct node *rightNode;
    struct node *leftNode;
};

typedef struct node *LINK;
LINK root;
LINK createTree();
int display(struct node *, string);
int main()
{
    root = createTree();
    display(root, ": data at the root");
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
int display(LINK root, string note)
{
    LINK tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    cout << "THE DATA IS THE :" << tempRoot->data << note << endl;
    display(tempRoot->leftNode, " data at left node ");
    display(tempRoot->rightNode, " data at the right node ");
}
