#include <bits/stdc++.h>
using namespace std;
// for extra space just convert it in one D array and then find median by firstly sorting it
// here condition of question is solve it in o(1) space
// here we basically use approch of
// firstly merge two sorted array
// we start merging from bottom
// after that wwe find median elememnt
void printVector(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int getMedian(vector<vector<int>> vec)
{
    int row = vec.size();
    int col = vec[0].size();
    int total = row * col;
    if (total % 2 != 0)
    {
        int midR = row / 2;
        int midC = col / 2;
        return vec[midR][midC];
    }
    else
    {
        int index = 1;
        int curr = vec[0][0];
        int prev = 0;
        int mid = total / 2;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (index > mid)
                {
                    return ((curr + prev) / 2);
                }
                prev = curr;
                curr = vec[i][j];
                index++;
            }
        }
    }
    return -1;
}
void mergeOptimise(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr2.size();
    int i = 0, j = 0, k = n - 1;

    while (i <= k && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}
int median(int r, int c, vector<vector<int>> &matrix)
{
    for (int i = matrix.size() - 1; i > 0; i--)
    {
        mergeOptimise(matrix[i - 1], matrix[i]);
    }
    printVector(matrix);
    return getMedian(matrix);
}
class Solution
{
public:
    //use binary search for this
    int median(vector<vector<int>> &m, int r, int c)
    {
        // code here
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            // Finding the minimum element
            if (m[i][0] < min) 
                min = m[i][0];

            // Finding the maximum element
            if (m[i][c - 1] > max)
                max = m[i][c - 1];
        }

        int desired = (r * c + 1) / 2;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int place = 0;

            // Find count of elements smaller than mid
            for (int i = 0; i < r; ++i)
                place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
            if (place < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r = 4, c = 3;
    vector<vector<int>> matrix = {
        {1, 2, 2},
        {2, 4, 4},
        {3, 4, 5},
        {3, 4, 5}};

    cout << median(r, c, matrix) << endl;

    return 0;
}