/*
we have board of n*n and inital co-ordinate (x,y) of knight
and moves k
find the probability of knight stays in move after k moves
*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<float>
#define vii vector<vector<float>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool valid_move(int row, int col, int n)
{
    if (row < 0 || col < 0 || row >= n || col >= n)
        return false;
    return true;
}
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << en;
    }
    cout << endl;
}
float knight_probability(int n, int k, int row, int col)
{
    vii curr(n, vi(n));
    vii next(n, vi(n));
    curr[row][col] = 1;
    for (int moves = 0; moves < k; moves++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (curr[i][j] == 0)
                    continue;
                int row_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
                int col_move[] = {1, 2, 2, 1, -1, -2, -2, -1};
                for (int curr_move = 0; curr_move < 8; curr_move++)
                {
                    int new_row = i + row_move[curr_move];
                    int new_col = j + col_move[curr_move];
                    if (valid_move(new_row, new_col, n))
                        next[new_row][new_col] += (curr[i][j] / 8);
                }
            }
        }
        curr = next;
        for (auto &li : next)
        {
            fill(li.begin(), li.end(), 0);
        }
    }
    float sum = 0;
    for (auto li : curr)
    {
        float temp = 0;
        sum += accumulate(li.begin(), li.end(), temp);
    }
    return sum;
}
int main()
{
    FAST;
    int n, r, c, k;
    cin >> n >> k >> r >> c;
    cout << knight_probability(n, k, r, c) << en;
    return 0;
}