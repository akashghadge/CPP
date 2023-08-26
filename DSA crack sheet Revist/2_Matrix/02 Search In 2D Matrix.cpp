/*
in first Binary Search find which row probably contains element and in second is element present or not
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int k)
    {
        int n = arr.size(), m = arr[0].size();
        int lo = 0, hi = n - 1;
        int r = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid][m - 1] == k)
            {
                return true;
            }
            else if (arr[mid][m - 1] > k)
            {
                r = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        lo = 0, hi = m - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[r][mid] == k)
            {
                return true;
            }
            else if (arr[r][mid] > k)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row_num = matrix.size();
        int col_num = matrix[0].size();

        int begin = 0, end = row_num * col_num - 1;

        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            int mid_value = matrix[mid / col_num][mid % col_num];

            if (mid_value == target)
            {
                return true;
            }
            else if (mid_value < target)
            {
                // Should move a bit further, otherwise dead loop.
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
}