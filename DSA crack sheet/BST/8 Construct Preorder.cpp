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
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// 4 1 2 3  5 6 7
Node *helper(vector<int> preorder, int *pointer, int min, int max)
{
    if (preorder.size() == *pointer)
        return NULL;
    
}
Node *preOrderToBST(vector<int> preorder)
{
    if (preorder.size() == 0)
        return NULL;

    int pointer = 0;
    helper(preorder, &pointer, INT_MIN, INT_MAX);
}
int main()
{
    FAST;

    return 0;
}