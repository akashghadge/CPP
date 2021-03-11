#include <iostream>
using namespace std;
#include "queue"
// declring structure
struct Node
{
    int data;
    struct Node *righNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;

Link newNode(int data){
    Link temp=(Link)malloc(sizeof(struct Node));
    temp->data=data;
    temp->leftNode=temp->righNode=NULL;
    return temp;
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

int MinMaxValue(Link root, int *min, int *max, int hd)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (*min > hd)
    {
        *min = hd;
    }
    else if (*max < hd)
    {
        *max = hd;
    }
    MinMaxValue(root->leftNode, min, max, hd - 1);
    MinMaxValue(root->righNode, min, max, hd + 1);
}

int printVerticalTrav(Link root, int line_no, int hd)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (line_no == hd)
    {
        cout << root->data << " ";
    }
    printVerticalTrav(root->leftNode, line_no, hd - 1);
    printVerticalTrav(root->leftNode, line_no, hd + 1);
}

void mainVertical(Link root)
{
    int min = 0;
    int max = 0;
    MinMaxValue(root, &min, &max, 0);
    int i=0;
    for ( i = min; i <= max; i++)
    {
        printVerticalTrav(root, i, 0);
        cout << endl;
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    Link root=newNode(1);
    root->leftNode=newNode(2);
    root->righNode=newNode(3);
    cout<<"Vertical order traversal"<<endl;
    
    mainVertical(root);
}