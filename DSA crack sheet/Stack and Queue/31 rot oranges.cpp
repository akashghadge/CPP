/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)
 

Constraints:
1 ≤ n, m ≤ 500


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
    int x, y, t;
    Node(int xNew, int yNew, int tNew)
    {
        x = xNew;
        y = yNew;
        t = tNew;
    }
};
void dispQ(queue<Node *> q)
{
    while (!q.empty())
    {
        cout << q.front()->x << " " << q.front()->y << " " << q.front()->t << endl;
        q.pop();
    }
    cout << endl;
}
bool isAllRot(vector<vector<int>> &grid)
{
    for (auto row : grid)
    {
        for (auto val : row)
        {
            if (val == 1)
                return false;
        }
    }
    return true;
}
void rot(vector<vector<int>> &grid, Node *rottenOrange, queue<Node *> &q)
{
    int x = rottenOrange->x;
    int y = rottenOrange->y;
    int t = rottenOrange->t;
    if (x + 1 < grid.size() && grid[x + 1][y] == 1)
    {
        grid[x + 1][y] = 2;
        Node *n = new Node(x + 1, y, t + 1);
        q.push(n);
    }
    if (x - 1 >= 0 && grid[x - 1][y] == 1)
    {
        grid[x - 1][y] = 2;
        Node *n = new Node(x - 1, y, t + 1);
        q.push(n);
    }
    if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
    {
        grid[x][y + 1] = 2;
        Node *n = new Node(x, y + 1, t + 1);
        q.push(n);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == 1)
    {
        grid[x][y - 1] = 2;
        Node *n = new Node(x, y - 1, t + 1);
        q.push(n);
    }
}
int orangesRotting(vector<vector<int>> &grid)
{
    // get all rotten oranges
    queue<Node *> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                Node *n = new Node(i, j, 0);
                q.push(n);
            }
        }
    }
    int time = 0;
    while (!q.empty())
    {
        Node *rottenOrange = q.front();
        q.pop();
        rot(grid, rottenOrange, q);
        time = q.back()->t;
    }
    if (isAllRot(grid))
    {
        return time;
    }
    else
    {
        return -1;
    }
}
int main()
{
    FAST;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << orangesRotting(grid) << endl;

    return 0;
}