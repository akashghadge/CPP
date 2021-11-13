/*
2d matrix given
0 and number
cant visit zeros maximum called component
only left right top bottom
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
void sol(vector<vector<int>> &gold, vector<vector<bool>> &visited, int row, int col, int sum, int *max_sum, vector<int> &bag)
{
    if (row < 0 || row >= gold.size() || col < 0 || col >= gold[0].size() || visited[row][col] || gold[row][col] == 0)
        return;

    visited[row][col] = true;
    bag.push_back(gold[row][col]);
    sol(gold, visited, row - 1, col, sum, max_sum, bag);
    sol(gold, visited, row + 1, col, sum, max_sum, bag);
    sol(gold, visited, row, col - 1, sum, max_sum, bag);
    sol(gold, visited, row, col + 1, sum, max_sum, bag);
    visited[row][col] = false;
}

void helper(vector<vector<int>> &gold, vector<vector<bool>> &visited, int row, int col, int sum, int *max_sum)
{
    for (int i = 0; i < gold.size(); i++)
    {
        for (int j = 0; j < gold[0].size(); j++)
        {
            if (gold[i][j] != 0 && !visited[i][j])
            {
                vector<int> bag;
                sol(gold, visited, i, j, 0, max_sum, bag);
                sum = accumulate(bag.begin(), bag.end(), 0);
                *max_sum = max(sum, *max_sum);
            }
        }
    }
}
int main()
{
    FAST;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gold(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gold[i][j];
        }
    }
    int max_sum = 0;
    helper(gold, visited, 0, 0, 0, &max_sum);
    cout << max_sum << en;
    return 0;
}