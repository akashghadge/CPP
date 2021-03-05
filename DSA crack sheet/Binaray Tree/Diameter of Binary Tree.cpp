#include <iostream>
using namespace std;
#include <chrono>
using namespace std ::chrono;

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

int max(int a, int b)
{
    return a > b ? a : b;
}
int height(Link root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lHeight = height(root->leftNode);
        int rHeight = height(root->righNode);
        return max(lHeight, rHeight) + 1;
    }
}

// basically diameter or widht of tree is the
// basically diameter of tree is height of left subtree and right subtree +1 so we can calculate is through

int diameter(Link root)
{
    if (root == NULL)
        return 0;

    // firstly calculate height
    int lheight = height(root->leftNode);
    int rheight = height(root->righNode);

    // call recursivly it
    int ldiameter = diameter(root->leftNode);
    int rdiameter = diameter(root->righNode);

    // return the max l+r+1 and ldiameter and rdiameter
    return max((lheight + rheight + 1), max(ldiameter, rdiameter));
}

int main()
{
    auto startTime = high_resolution_clock::now();
    root = create_bTree();
    int d = diameter(root);
    cout << "Diameter is :" << d << endl;
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    float finalDur = duration.count();
    float sec = finalDur / 1000000;
    cout << "Time taken :" << sec << " microsec" << endl;
}