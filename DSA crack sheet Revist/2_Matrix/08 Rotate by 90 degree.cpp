/*

*/
#include <bits/stdc++.h>
using namespace std;
void rotateby90(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        swap(matrix[low], matrix[high]);
        low++;
        high--;
    }
}
int main()
{
}