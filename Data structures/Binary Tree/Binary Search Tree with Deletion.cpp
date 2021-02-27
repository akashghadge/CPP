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
// it is used to find min value in that subttree
Link minValueNode(Link root)
{
    Link current = root;
    while (current && current->leftNode != NULL)
    {
        current = current->leftNode;
    }
    return current;
}

// function for delete node
Link deleteNode(Link root, int key)
{
    // base case that is if root is null :)
    if (root == NULL)
        return NULL;

    // if key is lesser then node would be in the left subtree
    if (root->data > key)
    {
        root->leftNode = deleteNode(root->leftNode, key);
    }
    // if key is greater then node in the right subtree
    else if (root->data < key)
    {
        root->rightNode = deleteNode(root->rightNode, key);
    }
    // now output node must be which one we like to delete i.e root->data == key
    else
    {
        // now we have three conditions
        // root has only right child
        if (root->leftNode == NULL)
        {
            Link temp = root->rightNode;
            free(root);
            return temp;
        }
        // root has only left child
        else if (root->rightNode == NULL)
        {
            Link temp = root->leftNode;
            free(root);
            return temp;
        }
        // root have both left and right child
        // here we should replace with inorder predecessor or succesor
        // now search successor
        //inorder successor means smallest element in the right subtree

        Link temp = minValueNode(root->rightNode);
        // make the successor current root by cloning it's data to root which we want to delete
        root->data = temp->data;
        // now delete that successor for avoid duplication
        root->rightNode = deleteNode(root->rightNode, temp->data);
    }
    return root;
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
    // Link lowest = minValueNode(root);
    // cout << lowest->data << endl;

    int data;
    cout << "which node would you like to delete" << endl;
    cin >> data;
    root = deleteNode(root, data);
    displayInorder(root);
}
