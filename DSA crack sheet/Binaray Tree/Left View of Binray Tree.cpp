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
// basically here first nodd we see from side of tree is left view of tree
// for this we print only one node for every level
// for first level root is printed
int leftViewUtil(Link root, int level, int *max_level)
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
    leftViewUtil(root->leftNode, level + 1, max_level);
    leftViewUtil(root->righNode, level + 1, max_level);
}

int leftView(Link root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// itrative approch
int leftViewItrative(Link root)
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
            // here we need to only print left most node i.e which is firstly go in to queue
            if (i == 1)
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
    leftView(root);
    cout << endl;
    cout << "Left view Itrative " << endl;
    leftViewItrative(root);
}