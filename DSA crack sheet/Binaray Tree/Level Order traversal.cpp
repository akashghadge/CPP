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
    // level order traversal means we traverse tree level by level
    // i.e if in first level root is present and second level roots left and right child and after level three second levels left child have two child and second level right child have right child
    queue<Link> q;
    Link curr = root;
    q.push(curr);
    while (!q.empty())
    {
        curr = q.front();
        cout << curr->data << endl;
        q.pop();
        if (curr->leftNode)
        {
            q.push(curr->leftNode);
        }
        if (curr->righNode)
        {
            q.push(curr->righNode);
        }
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    LevelOrderTraversal(root);
}