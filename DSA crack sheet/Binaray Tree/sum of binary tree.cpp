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
int max(int a, int b)
{
    return a > b ? a : b;
}

// basically write program to get sum of fulll tree
// and then update it to find max sum by storing max value and if higher is encounterd change ans
// wrapper function
int sumOfTree(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data + sumOfTree(root->leftNode, ans) + sumOfTree(root->righNode, ans);
    if (sum > ans)
    {
        ans = sum;
    }
    return sum;
}
//main function
int sumOfTreeUtil(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = INT8_MIN;
    sumOfTree(root, ans);
    return ans;
}
int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Original Tree :" << endl;
    display(root);
    // cout << "height of tree is : " << height(root) << endl;
    cout << "Sum Of tree :" << sumOfTreeUtil(root) << endl;
}