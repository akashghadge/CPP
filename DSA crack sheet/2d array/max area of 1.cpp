#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
// here we break problem in sub problem of largest reactangle subarray
// so we basically getting histograms of 1s and then we just calculate max area
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> lb(n);
        vector<int> rb(n);
        stack<int> st;
        //         for lb this
        st.push(0);
        lb[0] = -1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                lb[i] = -1;
            }
            else
            {
                lb[i] = st.top();
            }
            st.push(i);
        }
        //         clear stack for next step
        while (!st.empty())
        {
            st.pop();
        }
        // cout<<"hello"<<endl;
        //         for rb
        st.push(n - 1);
        rb[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                rb[i] = n;
            }
            else
            {
                rb[i] = st.top();
            }
            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i] * (rb[i] - lb[i] - 1);
            maxA = max(maxA, curr);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
        {
            return 0;
        }
        vector<int> row(matrix[0].size());
        int maxA = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    row[j]++;
                }
                else
                {
                    row[j] = 0;
                }
            }
            maxA = max(maxA, largestRectangleArea(row));
        }
        return maxA;
    }
};
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