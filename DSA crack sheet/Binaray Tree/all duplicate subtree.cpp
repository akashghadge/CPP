#include <iostream>
using namespace std;
#include "queue"
#include "unordered_map"
#include "stack"
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
string dUtil(Link root, unordered_map<string, int> &m, vector<string> &ans)
{
    if (root == NULL)
    {
        return "";
    }
    string str = "(";
    str += dUtil(root->leftNode, m, ans);
    str += to_string(root->data);
    str += dUtil(root->righNode, m, ans);
    str += ")";

    if (m[str] == 1)
    {
        cout << root->data << endl;

        ans.push_back(to_string(root->data));
    }
    m[str]++;
    return str;
}
int printDup(Link root)
{
    unordered_map<string, int> m;
    if (root == NULL)
    {
        return 0;
    }
    vector<string> ans;
    dUtil(root, m, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }
}

int main()
{
    cout << "Hello Akash" << endl;
    root = create_bTree();
    printDup(root);
}