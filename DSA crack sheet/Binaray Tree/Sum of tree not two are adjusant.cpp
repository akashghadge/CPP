#include <iostream>
using namespace std;
// declring structure
#include "vector"
#include <unordered_map>
struct Node
{
    int data;
    struct Node *righNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;
Link createNewNode(int val)
{
    Link newNode = (Link)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->leftNode = NULL;
    newNode->righNode = NULL;
    return newNode;
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
// here this problem is solve using same as dp problem
unordered_map<Link, int> dp;
int sumOfTree(Link root)
{
    if (!root)
    {
        return 0;
    }
    if (dp[root])
        return dp[root];
    int inc = root->data;
    if (root->leftNode)
    {
        inc += sumOfTree(root->leftNode->leftNode);
        inc += sumOfTree(root->leftNode->righNode);
    }
    if (root->righNode)
    {
        inc += sumOfTree(root->righNode->leftNode);
        inc += sumOfTree(root->righNode->righNode);
    }
    int exe = sumOfTree(root->leftNode) + sumOfTree(root->righNode);
    dp[root] = max(inc, exe);
    return dp[root];
}

int main()
{
    cout << "Hello Akash" << endl;
    Link root = create_bTree();
    cout << "One tree" << endl;
    display(root);
    cout << "Sum of Tree Wthout any two nodes are adjusant :" << sumOfTree(root) << endl;
}