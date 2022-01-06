/*
Akash is stuck in a N×N grid, where N is odd. The rows of the grid are numbered 1 to N from top to bottom, and the columns are numbered 1 to N from left to right. The cell at the intersection of the i-th row and j-th column will be denoted (i,j).

The grid has a unique center cell — ((N+1)/2,(N+1)/2). For example, when N=5 the center is cell (3,3).

Akash is currently at cell (xs,ys). He would like to reach the exit of the grid, which is located at the center. It is guaranteed that (xs,ys) is not the center.

Suppose Akash is at cell (x,y). He can make the following movements:

He can freely move along diagonals, i.e, to cells (x−1,y−1),(x−1,y+1),(x+1,y−1),(x+1,y+1)
He can move one step horizontally or vertically with the cost of 1 gold coin, i.e, to cells (x,y−1),(x,y+1),(x−1,y),(x+1,y)
Note that Akash is not allowed to make a move that will take him out of bounds of the grid.

Akash would like to minimize the number of coins required to reach the center. Please help him find this number.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, containing three space-separated integers N,xs,ys — the size of the grid and the coordinates of Akash's starting cell.
Output Format
For each test case, output in a single line the minimum number of gold coins Akash needs to reach the center.

Constraints
1≤T≤104
3≤N<2⋅104
N is always odd.
1≤xs,ys≤N
Sample Input 1 
2
3 2 1
5 3 1
Sample Output 1 
1
0
Explanation
Test case 1: For a 3×3 grid, the center is at (2,2). It is not possible to reach (2,2) from (2,1) using only diagonal moves. So, Akash will directly go to the center using 1 gold coin.



Test case 2: N=5, so the center is (3,3). Akash can go from (3,1) to (2,2) with a diagonal move, then from (2,2) to (3,3) with another diagonal move. So, he needs zero coins.
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

int util(int N, int row, int col, int target, int gold, int *gold_ans, vii &visited)
{
    if (row < 0 || col < 0 || col == N || row == N || visited[row][col])
    {
        return 0;
    }
    else if (row == target and col == target)
    {
        *gold_ans = min(*gold_ans, gold);
        return 0;
    }
    visited[row][col] = 1;
    // diagonals
    util(N, row + 1, col + 1, target, gold, gold_ans, visited);
    util(N, row - 1, col - 1, target, gold, gold_ans, visited);
    util(N, row + 1, col - 1, target, gold, gold_ans, visited);
    util(N, row - 1, col + 1, target, gold, gold_ans, visited);

    // top down
    util(N, row, col + 1, target, gold + 1, gold_ans, visited);
    util(N, row, col - 1, target, gold + 1, gold_ans, visited);
    util(N, row + 1, col, target, gold + 1, gold_ans, visited);
    util(N, row - 1, col, target, gold + 1, gold_ans, visited);

    visited[row][col] = 0;
    return 0;
}

int sol(int N, int row, int col)
{
    int target = N / 2;
    int gold_ans = 0;
    vii visited(N, vi(N));
    cout << "target" << target << en;
    util(N, row, col, target, 0, &gold_ans, visited);
    return gold_ans;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int row, col;
        cin >> N;
        cin >> col >> row;
        cout << sol(N, row - 1, col - 1) << en;
    }

    return 0;
}