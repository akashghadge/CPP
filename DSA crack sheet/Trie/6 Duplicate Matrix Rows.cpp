/*
Given a binary matrix your task is to find all unique rows of the given matrix.

Example 1:

Input:
row = 3, col = 4
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: 1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are 1 1 0 1 and
1 0 0 1 .
Your Task:
You only need to implement the given function uniqueRow(). The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix. The function should return the list of the unique row of the martrix. Do not read input, instead use the arguments given in the function.

Note: The drivers code print the rows "$" separated.

Expected Time Complexity: O(row * col)
Expected Auxiliary Space: O(row * col)

Constraints:
1<=row,col<=40
0<=M[][]<=1


*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<int>> vec = uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}
// } Driver Code Ends

typedef struct Node
{
    struct Node *arr[2];
    bool flag;
    Node()
    {
        for (int i = 0; i < 2; i++)
        {
            arr[i] = NULL;
        }
        flag = false;
    }
} Node;

class Trie
{
public:
    bool isPresent(Node *node, int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int idx = arr[i];
            if (!node->arr[idx])
            {
                return false;
            }
            node = node->arr[idx];
        }
        return node->flag;
    }

    void insert(Node *node, int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int idx = arr[i];
            if (!node->arr[idx])
            {
                node->arr[idx] = new Node();
            }
            node = node->arr[idx];
        }
        node->flag = true;
    }
};

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    // Your code here
    Trie t;
    Node *root = new Node();
    vector<vector<int>> res;
    for (int i = 0; i < row; i++)
    {
        if (!t.isPresent(root, M[i], col))
        {
            t.insert(root, M[i], col);
            vector<int> inner(M[i], M[i] + col);
            res.push_back(inner);
        }
    }

    return res;
}