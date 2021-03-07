#include <iostream>
using namespace std;
#include <stack>
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

Link Inorder(Link root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Inorder(root->leftNode);
    cout << root->data << " ";
    Inorder(root->righNode);
}
// stack approch
void Inorder_Itrative(Link root)
{
    Link temp = root;
    stack<Link> s;

    while (!s.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->leftNode;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << endl;
            temp = temp->righNode;
        }
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    Inorder(root);
    cout << "Itrative approch" << endl;
    Inorder_Itrative(root);
}