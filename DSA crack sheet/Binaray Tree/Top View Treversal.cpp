#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
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

// i know that hash map solution does not contain any good imprsion in interview
// but it is only one can i solve now i will update it latter

int TopView(Link root)
{
    // if root is null
    if (root == NULL)
    {
        return 0;
    }

    // make map for storing if vertically element is printed or not and and queue for Node * and vertical distance
    unordered_map<int, int> m;
    queue<pair<Link, int>> q;
    // push first pair so q.is not empty any way
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        // get first element of queue
        pair<Link, int> pairCurr = q.front();
        Link curr = pairCurr.first;
        int val = pairCurr.second;
        q.pop();
        // find there is previos element on that vertical position
        if (m.find(val) == m.end())
        {
            // if have print it
            cout << curr->data << " " << endl;
            m[val] = curr->data;
        }
        if (curr->leftNode)
        {
            q.push(make_pair(curr->leftNode, val - 1));
        }
        if (curr->righNode)
        {
            q.push(make_pair(curr->righNode, val + 1));
        }
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    TopView(root);
}