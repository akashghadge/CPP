/*

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10, M = 10;
void sortMat(int data[N][M], int row, int col)
{

    // Number of elements in matrix
    int size = row * col;

    // Loop to sort the matrix
    // using Bubble Sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
 
            // Condition to check
            // if the Adjacent elements
            if (data[j / col][j % col] > data[(j + 1) / col][(j + 1) % col])
            {

                // Swap if previous value is greater
                int temp = data[j / col][j % col];
                data[j / col][j % col] = data[(j + 1) / col][(j + 1) % col];
                data[(j + 1) / col][(j + 1) % col] = temp;
            }
        }
    }
}
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> v)
{
    // code here
    vector<int> temp;
    for (auto i : v)
        temp.insert(temp.end(), i.begin(), i.end());
    sort(temp.begin(), temp.end());

    int counter = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j] = temp[counter++];
        }
    }
    return v;
}

int main()
{
}