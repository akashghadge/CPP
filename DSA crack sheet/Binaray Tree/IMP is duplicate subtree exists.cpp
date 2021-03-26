#include <iostream>
using namespace std;
#include <unordered_map>
#include "string"
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
int display(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    display(root->leftNode);
    cout << root->data << " " << endl;
    display(root->righNode);
}

unordered_map<string, int> map;

string solve(Link root)
{
    string s = "$";
    if (root == NULL)
    {
        return s;
    }
    if (!root->leftNode && !root->righNode)
    {
        s += to_string(root->data);
        return s;
    }

    s += to_string(root->data);
    s += solve(root->leftNode);
    s += solve(root->righNode);
    map[s]++;
}
bool isDuplicateSubTree(Link root)
{
    map.clear();
    solve(root);
    for (auto x : map)
    {
        if (x.second >= 2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Original Tree :" << endl;
    display(root);
    cout << " Is Duplicate subtree : " << isDuplicateSubTree(root);
}