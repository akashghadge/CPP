#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
bool checkArea(vector<vector<int>> &mat, int y, int x)
{
    x--;
    y--;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (i + y >= mat.size() || j + x >= mat[0].size())
            {
                continue;
            }
            int ct = 0;
            for (int k = i; k <= i + y; k++)
            {
                for (int m = j; m <= j + x; m++)
                {
                    if (mat[k][m] == 1)
                    {
                        ct++;
                    }
                }
            }
            if (ct == (i + y + 1) * (j + x + 1))
            {
                // cout << "values " << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}
int maxArea(vector<vector<int>> &mat)
{
    int N = mat.size(), M = mat[0].size();
    int i = N, j = M;
    int maxA = INT8_MIN;
    while (i >= 0)
    {
        j = M;
        while (j >= 0)
        {
            if (checkArea(mat, i, j))
            {
                // cout << i << " " << j << endl;
                // return (i) * (j);
                maxA = max(i * j, maxA);
            }
            j--;
        }
        i--;
    }
    return maxA;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> mat =
        {
            {0, 1, 1},
            {0, 1, 1},
            {0, 1, 1}};
    cout << maxArea(mat) << endl;
    return 0;
}