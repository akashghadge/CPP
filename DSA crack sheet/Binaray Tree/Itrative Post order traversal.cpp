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

int postOreder(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        postOreder(root->leftNode);
        postOreder(root->righNode);
        cout << root->data << " ";
    }
}

// with only one stack
void postOrder_itrative(Link root)
{
    stack<Link> s;

    // for preorder first push the root node in it so here stack is always not empty
    s.push(root);
    Link curr = root;

    stack<int> out;
    while (!s.empty())
    {
        // pop elemen and print it
        curr = s.top();
        out.push(curr->data);
        s.pop();
        // here we need push right first here
        if (curr->leftNode)
        {
            s.push(curr->leftNode);
        }
        if (curr->righNode)
        {
            s.push(curr->righNode);
        }
    }

    while (!out.empty())
    {
        int data = out.top();
        out.pop();
        cout << data << " ";
    }
}

int main()
{
    root = create_bTree();
    cout << "Pre Order traversal :" << endl;
    postOreder(root);
    cout << endl;
    cout << "Itrative approch" << endl;
    postOrder_itrative(root);
}