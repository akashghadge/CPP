#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *getInPre(Node *curr, Node *root)
{
    while (curr->right != NULL && curr->right != root)
    {
        curr = curr->right;
    }
    return curr;
}
vector<int> morris(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    Node *curr = root;
    while (curr != NULL)
    {
        Node *leftNode = curr->left;
        if (leftNode != NULL)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *inPre = getInPre(leftNode, curr);
            if (inPre->right == NULL)
            {
                res.push_back(curr->data);
                inPre->right = curr;
                curr = curr->left;
            }
            else
            {
                inPre->right = NULL;
                curr = curr->right; 
            }
        }
    }
}
int main()
{
    FAST;

    return 0;
}