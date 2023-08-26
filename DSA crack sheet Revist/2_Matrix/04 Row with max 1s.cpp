/*

*/
#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int ans = 0;
    int r = -1;
    int i = 0, j = m - 1;
    while (i < n and j >= 0)
    {
        if (arr[i][j])
        {
            ans = j + 1;
            r = i;
            j--;
        }
        else
        {
            i++;
        }
    }
    return r;
}
int main()
{
}