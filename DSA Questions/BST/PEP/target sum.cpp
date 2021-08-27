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
    Node(int newData)
    {
        data = newData;
        left = right = NULL;
    }
};
bool find(Node *root, int val)
{
    if (root == NULL)
        return false;
    else if (val < root->data)
        return find(root->left, val);
    else if (val > root->data)
        return find(root->right, val);
    else
        return true;
}
void helper(Node *root, int k, vector<pair<int, int>> &res, Node *perRoot)
{
    if (root == NULL)
        return;
    int temp = k - root->data;
    helper(root->left, k, res, perRoot);
    if (find(perRoot, temp))
        res.push_back(make_pair(root->data, temp));
    helper(root->right, k, res, perRoot);
}
vector<pair<int, int>> targetSum(Node *root, int k)
{
    vector<pair<int, int>> res;
    helper(root, k, res, root);
    return res;
}
int main()
{
    FAST;

    return 0;
}