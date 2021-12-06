/*

You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
4. You are standing in top-left cell and are required to move to bottom-right cell.
5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
7. You are required to traverse through the matrix and print the cost of the path which is least costly.
8. Also, you have to print all the paths with minimum cost.
Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements
Output Format
Check the sample output and question video.
Question Video

  COMMENTConstraints
1 <= n <= 10^2
1 <= m <= 10^2
0 <= e1, e2, .. n * m elements <= 1000
Sample Input
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1
Sample Output
23
HVVHHVHVHV
HVVHHVHHVV

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Node
{
public:
    int i;
    int j;
    string ans;
    Node(int newI, int newJ, string initAns)
    {
        i = newI;
        j = newJ;
        ans = initAns;
    }
};
void sol(vii grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vii dp(n, vi(m));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int curr_grid = grid[i][j];
            if (i == n - 1 && j == m - 1)
                dp[i][j] = curr_grid;
            else if (i == n - 1)
                dp[i][j] = dp[i][j + 1] + curr_grid;

            else if (j == m - 1)
                dp[i][j] = dp[i + 1][j] + curr_grid;
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + curr_grid;
            }
        }
    }
    Node *temp = new Node(0, 0, "");
    queue<Node *> q;
    q.push(temp);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        int i = curr->i, j = curr->j;
        string ans = curr->ans;
        if (i == n - 1 && j == m - 1)
            cout << curr->ans << en;
        else if (i == n - 1)
        {
            q.push(new Node(i, j + 1, ans + "H"));
        }

        else if (j == m - 1)
        {
            q.push(new Node(i + 1, j, ans + "V"));
        }
        else
        {
            if (dp[i + 1][j] == dp[i][j + 1])
            {
                q.push(new Node(i, j + 1, ans + "H"));
                q.push(new Node(i + 1, j, ans + "V"));
            }
            else if (dp[i + 1][j] < dp[i][j + 1])
            {
                q.push(new Node(i + 1, j, ans + "V"));
            }
            else
            {
                q.push(new Node(i, j + 1, ans + "H"));
            }
        }
    }
}
int main()
{
    FAST;
    int N, M;
    cin >> N >> M;
    vector<vi> grid(N, vi(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }
    sol(grid);
    return 0;
}