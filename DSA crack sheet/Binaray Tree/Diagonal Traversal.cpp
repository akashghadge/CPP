#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
#include <vector>
#include "stack"
// declring structure
struct Node
{
    int data;
    struct Node *rightNode;
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
    newnode->rightNode = create_bTree();
    return newnode;
}

vector<int> diagonalTraversal(Link root)
{
    queue<Link> q;
    vector<int> vec;
    q.push(root);
    while (!q.empty())
    {
        Link temp = q.front();
        q.pop();
        while (temp)
        {
            vec.push_back(temp->data);
            if (temp->leftNode)
            {
                q.push(temp->leftNode);
            }
            temp = temp->rightNode;
        }
    }
    return vec;
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    vector<int> vec = diagonalTraversal(root);
    vector<int>::iterator itr = vec.begin();
    cout << "printing output" << endl;
    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout << *itr << " " << endl;
    }
}