/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/

#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}