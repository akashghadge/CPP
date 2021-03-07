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

int preOreder(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        cout << root->data << " ";
        preOreder(root->leftNode);
        preOreder(root->righNode);
    }
}

void preOrder_itrative(Link root)
{
    stack<Link> s;

    // for preorder first push the root node in it so here stack is always not empty
    s.push(root);
    Link curr = root;
    while (!s.empty())
    {
        // pop elemen and print it
        curr = s.top();
        cout << curr->data << " ";
        s.pop();
        // firsty push the right element so we can access it last and then left so we can access it first i.e. root left right
        if (curr->righNode)
        {
            s.push(curr->righNode);
        }
        if (curr->leftNode)
        {
            s.push(curr->leftNode);
        }
    }
}

int main()
{
    root = create_bTree();
    cout << "Pre Order traversal :" << endl;
    preOreder(root);
    cout << endl;
    cout << "Itrative approch" << endl;
    preOrder_itrative(root);
}