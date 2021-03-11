#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
#include "stack"
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

int BottomView(Link root)
{
    // if root is null
    if (root == NULL)
    {
        return 0;
    }
    // get first level order traversal
    queue<pair<Link, int>> q;
    unordered_map<int, int> mapCurr;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Link, int> pairCurr = q.front();
        Link curr = pairCurr.first;
        int val = pairCurr.second;
        q.pop();
        // push every element according to its hd if
        // here main plot is map value is overright again and again so that last access element is save in map
        mapCurr[val] = curr->data;

        if (curr->leftNode)
        {
            q.push(make_pair(curr->leftNode, val - 1));
        }
        if (curr->righNode)
        {
            q.push(make_pair(curr->righNode, val + 1));
        }
    }
    for (auto i = mapCurr.begin(); i != mapCurr.end(); ++i)
    {
        cout << i->second << endl;
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    BottomView(root);
}