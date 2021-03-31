#include <iostream>
using namespace std;
#include "stack"
// declring structure
#include "vector"
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

bool kUtil(Link root, int target, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (kUtil(root->leftNode, target, ans))
    {
        ans.push_back(root->data);
        return true;
    }
    else if (kUtil(root->righNode, target, ans))
    {
        ans.push_back(root->data);
        return true;
    }
    return false;
}
// here this problem is solve using cheacking is node is target node or not if node is target node then return true otherwise false
// then recursivly cheack of both subtree and then push all ancestors
int KthAncestor(Link root, int target, int k)
{
    vector<int> ans;
    if (!root)
    {
        return -1;
    }
    kUtil(root, target, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Ancestors :" << ans[i] << endl;
    }
    if ((ans.size() - k) >= 0)
    {
        return ans[ans.size() - k];
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout << "Hello Akash" << endl;
    Link root = create_bTree();
    cout << "One tree" << endl;
    display(root);
    int result = KthAncestor(root, 4, 2);
    cout << "Result is :" << result << endl;
}