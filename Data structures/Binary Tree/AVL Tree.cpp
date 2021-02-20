#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    int height;
};
typedef struct Node *Link;
Link root = NULL;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}
int getBalanced(Link node)
{
    // it is differce betweeen height of left sub tree and right subtree
    if (node == NULL)
        return 0;
    return (height(node->left) - height(node->right));
}
Link newNode(int data)
{
    Link newnode = (Link)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->height = 1; //leaf always has height of 1
    return (newnode);
}

Link rightRotate(Link y)
{
    // getting duplicate links
    Link x = y->left;
    Link T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Link leftRotate(Link x)
{
    // getting duplicate links
    Link y = x->right;
    Link T2 = y->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    // update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
Link insertNode(Link root, int insertData)
{
    if (root == NULL)
    {
        return newNode(insertData);
    }
    if (root->data > insertData)
    {
        root->left = insertNode(root->left, insertData);
    }
    else if (root->data < insertData)
    {
        root->right = insertNode(root->right, insertData);
    }
    else
    {
        return root;
    }

    // updataing height of the root(node) after inserting leaf and due to recrsive approch it will updated back every parent to parent nodes
    root->height = 1 + max(height(root->left), height(root->right));

    // for cheacking how much balance factor will be
    int balance = getBalanced(root);

    // first case is left left then apply right rotation
    if (balance > 1 && insertData < root->left->data)
    {
        return rightRotate(root);
    }
    // right right conditioon leftratation
    if (balance < -1 && insertData > root->right->data)
    {
        return leftRotate(root);
    }
    // left right condition first do the left ratation and do the right rotation
    if (balance > 1 && insertData > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left condition r rota and l rotation
    if (balance < 1 && insertData < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inOrder(Link root)
{
    root->data;
    if (root != NULL)
    {
        cout << "The value at " << root->height << " is :" << root->data << endl;
        inOrder(root->left);
        inOrder(root->right);
    }
}

int main()
{
    Link root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    // root = insertNode(root, 40);
    // root = insertNode(root, 50);
    // root = insertNode(root, 25);
    inOrder(root);
}