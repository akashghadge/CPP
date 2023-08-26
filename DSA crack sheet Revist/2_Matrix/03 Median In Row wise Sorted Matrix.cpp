/*

*/
#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &matrix, int R, int C)
{
    int min = 1, max = 2000;
    int desired = (R * C + 1) / 2;

    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < R; ++i)
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

        if (place < desired) // important condition
            min = mid + 1;
        else
            max = mid;
    }

    return min;
}
int main()
{
}