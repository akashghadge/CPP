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
int morrisInorder(Node *root)
{
    int c = 0;
    if (root == NULL)
        return c;
    Node *curr = root;
    while (curr != NULL)
    {
        Node *leftNode = curr->left;
        if (leftNode != NULL)
        {
            c++;
            curr = curr->right;
        }
        else
        {
            Node *inPre = getInPre(leftNode, curr);
            if (inPre->right == NULL)
            {
                inPre->right = curr;
                curr = curr->left;
            }
            else
            {
                inPre->right = NULL;
                c++;
                curr = curr->right;
            }
        }
    }
    return c;
}

int getMedian(Node *root, int target)
{
    int c = 0;
    if (root == NULL)
        return c;
    Node *curr = root;
    while (curr != NULL)
    {
        Node *leftNode = curr->left;
        if (leftNode != NULL)
        {
            c++;
            // returning current node
            if (c == target)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            Node *inPre = getInPre(leftNode, curr);
            if (inPre->right == NULL)
            {
                inPre->right = curr;
                curr = curr->left;
            }
            else
            {
                inPre->right = NULL;
                c++;
                // returning current
                if (c == target)
                    return curr->data;
                curr = curr->right;
            }
        }
    }
}
int median(Node *root)
{
    int c = morrisInorder(root);
    if (c % 2 == 0)
        c /= 2;
    else
    {
        c++;
        c /= 2;
    }

    return getMedian(root, c);
}
int main()
{
    FAST;

    return 0;
}