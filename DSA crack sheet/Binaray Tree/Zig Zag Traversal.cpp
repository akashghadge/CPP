#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
#include <vector>
#include "stack"
// declring structure
struct Node
{
    int data;
    struct Node *rightNode;
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
    newnode->rightNode = create_bTree();
    return newnode;
}

// usign deque data sttructure
vector<int> ZigZag(Link root)
{
    deque<Link> d;
    vector<int> vec;
    if (root == NULL)
    {
        return vec;
    }
    vec.push_back(root->data);
    d.push_back(root);
    int level = 1;
    Link temp = NULL;

    while (!d.empty())
    {
        int n = d.size();
        for (int i = 0; i < n; i++)
        {
            // for poping it according to the situation
            if (level % 2 == 0)
            {
                temp = d.back();
                d.pop_back();
            }
            else
            {
                temp = d.front();
                d.pop_front();
            }

            // pushing tech
            if (level % 2 == 0)
            {
                if (temp->leftNode)
                {
                    d.push_front(temp->leftNode);
                    vec.push_back(temp->leftNode->data);
                }

                if (temp->rightNode)
                {
                    d.push_front(temp->rightNode);
                    vec.push_back(temp->rightNode->data);
                }
            }
            else if (level % 2 != 0)
            {
                if (temp->rightNode)
                {
                    d.push_back(temp->rightNode);
                    vec.push_back(temp->rightNode->data);
                }
                if (temp->leftNode)
                {
                    d.push_back(temp->leftNode);
                    vec.push_back(temp->leftNode->data);
                }
            }
        }
        level++;
    }
    return vec;
}
// usign two stacks
vector<int> ZigZagUsingStacks(Link root)
{
    stack<Link> currentLevel;
    stack<Link> nextLevel;
    currentLevel.push(root);
    vector<int> vec;
    bool leftToright = true;
    while (!currentLevel.empty())
    {
        Link temp = currentLevel.top();
        currentLevel.pop();
        vec.push_back(temp->data);
        if (leftToright)
        {
            if (temp->leftNode)
            {
                nextLevel.push(temp->leftNode);
            }
            if (temp->rightNode)
            {
                nextLevel.push(temp->rightNode);
            }
        }
        else
        {
            if (temp->rightNode)
            {
                nextLevel.push(temp->rightNode);
            }
            if (temp->leftNode)
            {
                nextLevel.push(temp->leftNode);
            }
        }
        if (currentLevel.empty())
        {
            leftToright = !leftToright;
            swap(currentLevel, nextLevel);
        }
    }
    return vec;
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    vector<int> vec = ZigZagUsingStacks(root);
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << endl;
    }
}