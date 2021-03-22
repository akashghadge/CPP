#include <iostream>
using namespace std;
#include "stack"

struct Node
{
    int data;
    struct Node *righNode;
    struct Node *leftNode;
};
typedef struct Node *Link;
Link root;
Link createNode(int data)
{
    Link newnode = (Link)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->leftNode = NULL;
    newnode->righNode = NULL;
    return newnode;
}
int display(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    display(root->leftNode);
    display(root->righNode);
    cout << root->data << " " << endl;
}
int serchIndex(int *arr, int value, int strt, int end)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
static int preIndex = 0;

Link createUtil(int *inorder, int *preorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    Link root = createNode(preorder[preIndex++]);
    int inIndex = serchIndex(inorder, start, end, root->data);

    if (start == end)
    {
        return root;
    }

    root->leftNode = createUtil(inorder, preorder, start, inIndex - 1);
    root->righNode = createUtil(inorder, preorder, inIndex + 1, end);
    return root;
}

Link createFromPreIn(int *inorder, int *preOrder, int size)
{
    preOrder = 0;
    return createUtil(inorder, preOrder, 0, size - 1);
}
int main()
{
    cout << "Hello Akash" << endl;
    int inorder[8] = {4, 2, 1, 7, 5, 8, 3, 6};
    int preOrder[8] = {1, 2, 4, 3, 5, 7, 8, 6};
    int size = 8;
    Link root = createFromPreIn(inorder, preOrder, size);
    display(root);
}