#include <iostream>
using namespace std;
#include <queue>
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

// recursive call
// basically here first nodd we see from right side of tree is right view of tree
// for this we print only one node for every level
// for first level root is printed
/*
    from left view you need to just change sequence of use of util function call 
    in left view use first leftNode and for right use rightNode
*/
int rightViewUtil(Link root, int level, int *max_level)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (level > *max_level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    rightViewUtil(root->righNode, level + 1, max_level);
    rightViewUtil(root->leftNode, level + 1, max_level);
}

int rightView(Link root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

// itrative approch
int rightViewItrative(Link root)
{
    if (root == NULL)
    {
        return NULL;
    }

    queue<Link> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Link temp = q.front();
            q.pop();
            // here we need to only print right most node i.e which is last to go in to queue i.e. n
            if (i == n)
            {
                cout << temp->data << " ";
            }
            if (temp->leftNode != NULL)
            {
                q.push(temp->leftNode);
            }
            if (temp->righNode != NULL)
            {
                q.push(temp->righNode);
            }
        }
    }
}

int main()
{
    root = create_bTree();
    cout << "Left view of the binray tree" << endl;
    rightView(root);
    cout << endl;
    cout << "Left view Itrative " << endl;
    rightViewItrative(root);
}