/*
Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)

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
struct Node
{
    int x, y, steps;
    Node(int newX, int newY, int newSteps)
    {
        x = newX;
        y = newY;
        steps = newSteps;
    }
};
int bfs(int y, int x, int steps, vector<vector<int>> grid)
{
    queue<Node *> q;
    Node *n = new Node(y, x, 0);
    int N = grid.size();
    int M = grid[0].size();
    q.push(n);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        // up
        if (y + 1 < N && grid[y + 1][x] == 1)
        {
            return curr->steps + 1;
        }
        else
        {
            Node *n = new Node(y + 1, x, curr->steps + 1);
            q.push(n);
        }
        // down
        if (y - 1 >= 0 && grid[y - 1][x] == 1)
        {
            return curr->steps + 1;
        }
        else
        {
            Node *n = new Node(y - 1, x, curr->steps + 1);
            q.push(n);
        }
        // right
        if (x + 1 < M && grid[y][x + 1] == 1)
        {
            return curr->steps + 1;
        }
        else
        {
            Node *n = new Node(y, x + 1, curr->steps + 1);
            q.push(n);
        }
        // left
        if (x - 1 >= 0 && grid[y][x - 1] == 1)
        {
            return curr->steps + 1;
        }
        else
        {
            Node *n = new Node(y, x - 1, curr->steps + 1);
            q.push(n);
        }
    }
    return 0;
}
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    queue<Node *> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                Node *n = new Node(j, i, 0);
                q.push(n);
            }
        }
    }
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int val = bfs(curr->y, curr->x, curr->steps, grid);
        grid[curr->y][curr->x] = val;
    }
    return grid;
}
int main()
{
    FAST;

    return 0;
}