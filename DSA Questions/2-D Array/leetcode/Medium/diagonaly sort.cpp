/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
Example 2:

Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
// approch is straight forword
vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int i = 0;
    int j = mat[0].size();
    while (i != mat.size())
    {
        int x = j;
        int y = i;
        vector<int> vec;
        while (x != mat[0].size() && y != mat.size())
        {
            vec.push_back(mat[y][x]);
            y++;
            x++;
        }
        sort(vec.begin(), vec.end());
        x = j;
        y = i;
        int k = 0;
        while (x != mat[0].size() && y != mat.size())
        {
            mat[y][x] = vec[k];
            x++;
            k++;
            y++;
        }
        if (j > 0)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return mat;
}
// time O(n)*(O(n)+O(nLogn)+O(n)) ==== O(n*n*Logn)
// space O(n);
int main()
{
}