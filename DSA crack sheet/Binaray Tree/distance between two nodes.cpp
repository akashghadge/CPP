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

// here question is find distance between two nodes
// here firstly we find lca then we just count levels from lca and return level of both nodes from lca
// and add it and return it
Link findLCA(Link root, int n1, int n2)
{
    // for root is NULL
    if (root == NULL)
        return NULL;
    // any of one node is encounter return it
    if (root->data == n1 || root->data == n2)
        return root;
    // if note there then find left and right subtree
    Node *left_lca = findLCA(root->leftNode, n1, n2);
    Node *right_lca = findLCA(root->rightNode, n1, n2);
    // if both lca_left and right present then return it
    if (left_lca && right_lca)
        return root;
    // if only one present then return it
    return (left_lca != NULL) ? left_lca : right_lca;
}
int findLevel(Node *root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return level;

    int left = findLevel(root->leftNode, k, level + 1);
    if (left == -1)
        return findLevel(root->rightNode, k, level + 1);
    return left;
}
int findDist(Link root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    Link lca = findLCA(root, a, b);
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    return d1 + d2;
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << findDist(root, 3, 2);
}