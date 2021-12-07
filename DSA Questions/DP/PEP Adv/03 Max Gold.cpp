/*
You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.
8. Also, you have to print all paths with maximum gold.
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
33
4 d3 d1 d2 d3 d1 

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
void gold(vii grid)
{
    if (grid.size() == 0)
        return;
    int n = grid.size();
    int m = grid[0].size();
    vii dp(n, vi(m));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = grid[i][j];
            else if (j == m - 1)
                dp[i][j] = grid[i][j];
            else if (i == 0)
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + grid[i][j];
            else if (i == n - 1)
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + grid[i][j];
            else
            {
                int max_gold = max(dp[i + 1][j + 1], dp[i - 1][j + 1]);
                dp[i][j] = max(max_gold, dp[i][j + 1]) + grid[i][j];
            }
        }
    }
    queue<Node *> q;
    int max_box = INT_MIN;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (max_box < dp[i][0])
        {
            pos = i;
            max_box = dp[i][0];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max_box == dp[i][0])
        {
            q.push(new Node(i, 0, to_string(i) + " "));
        }
    }
    cout << max_box << en;
    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();
        int i = curr_node->i;
        int j = curr_node->j;
        string ans = curr_node->ans;
        if (curr_node->j == m - 1)
            cout << curr_node->ans << en;
        else if (i == 0)
        {
            int max_of_all = max(dp[i + 1][j + 1], dp[i][j + 1]);
            if (max_of_all == dp[i][j + 1])
                q.push(new Node(i, j + 1, ans + "d2 "));
            if (max_of_all == dp[i + 1][j + 1])
                q.push(new Node(i + 1, j + 1, ans + "d3 "));
        }
        else if (i == n - 1)
        {
            int max_of_all = max(dp[i - 1][j + 1], dp[i][j + 1]);
            if (max_of_all == dp[i - 1][j + 1])
                q.push(new Node(i - 1, j + 1, ans + "d1 "));
            if (max_of_all == dp[i][j + 1])
                q.push(new Node(i, j + 1, ans + "d2 "));
        }
        else
        {
            int max_of_all = max(dp[i - 1][j + 1], dp[i][j + 1]);
            max_of_all = max(max_of_all, dp[i + 1][j + 1]);
            if (max_of_all == dp[i - 1][j + 1])
                q.push(new Node(i - 1, j + 1, ans + "d1 "));
            if (max_of_all == dp[i][j + 1])
                q.push(new Node(i, j + 1, ans + "d2 "));
            if (max_of_all == dp[i + 1][j + 1])
                q.push(new Node(i + 1, j + 1, ans + "d3 "));
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
    gold(grid);
    return 0;
}