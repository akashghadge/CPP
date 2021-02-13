#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *rightNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;

Link insertNode(int, Link);

Link createNewNode(int num)
{
    Link newnode = (Link)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->leftNode = NULL;
    newnode->rightNode = NULL;
    return newnode;
}

Link insertNode(int num, Link node)
{
    if (node == NULL)
        return createNewNode(num);

    if (num < node->data)
        node->leftNode = insertNode(num, node->leftNode);
    else if (num > node->data)
    {
        node->rightNode = insertNode(num, node->rightNode);
    }
    return node;
}
int displayPreorder(Link root)
{
    Link tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    cout << "THE DATA IS THE :" << tempRoot->data << endl;
    displayPreorder(tempRoot->leftNode);
    displayPreorder(tempRoot->rightNode);
}
int displayInorder(Link root)
{
    Link tempRoot = root;
    if (tempRoot == NULL || tempRoot->data == 0)
    {
        return 0;
    }
    displayInorder(tempRoot->leftNode);
    cout << "THE DATA IS THE :" << tempRoot->data << " " << endl;
    displayInorder(tempRoot->rightNode);
}
Link createBST(int *arr, int size)
{
    if (size <= 0)
    {
        cout << "input array is empty" << endl;
    }
    else if (size == 1)
    {
        Link root = createNewNode(arr[0]);
        return root;
    }
    else
    {
        Link root = createNewNode(arr[0]);
        for (int i = 1; i < size; i++)
        {
            insertNode(arr[i], root);
        }
        return root;
    }
}
int main()
{
    int size;
    cout << "Please enter array size :" << endl;
    cin >> size;
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "Please enter element for " << i << endl;
        cin >> arr[i];
    }
    for (i = 0; i < size; i++)
    {
        cout << "Element at " << i << "index is :" << arr[i] << endl;
    }
    root = createBST(arr, size);
    displayInorder(root);
}
