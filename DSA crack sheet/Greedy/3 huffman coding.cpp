/*

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Sol
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
    };
    struct compare
    {
        bool operator()(struct Node *p1, struct Node *p2)
        {
            if (p1->data == p2->data)
                return false;
            return p1->data > p2->data;
        }
    };
    void preorder(vector<string> &res, Node *root, string str)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
            res.push_back(str);
        preorder(res, root->left, str + "0");
        preorder(res, root->right, str + "1");
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, compare> pq;
        for (int i = 0; i < N; i++)
        {
            Node *n = new Node(f[i]);
            pq.push(n);
        }

        while (pq.size() != 1)
        {
            Node *first = pq.top();
            pq.pop();
            Node *second = pq.top();
            pq.pop();
            Node *res = new Node(first->data + second->data);
            res->left = first;
            res->right = second;
            pq.push(res);
        }
        Node *root = pq.top();
        vector<string> res;
        preorder(res, root, "");
        return res;
    }
};
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    FAST;
    Sol s;
    vector<int> f = {5, 9, 12, 13, 16, 45};
    string str = "abcdef";
    vector<string> res = s.huffmanCodes(str, f, 6);
    printVector(res);
    return 0;
}