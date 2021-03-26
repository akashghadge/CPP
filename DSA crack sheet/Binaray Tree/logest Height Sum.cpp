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
void sumUtil(Link root, int sum, int height, int &maxSum, int &maxHeight)
{
    // for getting sum firstly traverse upto the leaf node
    // for only leaf node cheack height and sum and update accordingly
    if (!root)
    {
        if (height > maxHeight)
        {
            maxHeight = height;
            maxSum = sum;
        }
        else if (height == maxHeight && sum > maxSum)
        {
            maxSum = sum;
        }
        return;
    }
    // call recursively upto leaf increase height and sum
    sumUtil(root->leftNode, sum + root->data, height + 1, maxSum, maxHeight);
    sumUtil(root->righNode, sum + root->data, height + 1, maxSum, maxHeight);
}
// wrapper function
int sumOfLongRootToLeafPath(Node *root)
{
    int maxSum = INT8_MIN;
    int maxHeight = 0;
    int sum = 0;
    int height = 0;
    sumUtil(root, sum, height, maxSum, maxHeight);
    return maxSum;
}
int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    cout << "Original Tree :" << endl;
    display(root);
    // cout << "height of tree is : " << height(root) << endl;
    cout << "Sum Of tree :" << sumOfLongRootToLeafPath(root) << endl;
}