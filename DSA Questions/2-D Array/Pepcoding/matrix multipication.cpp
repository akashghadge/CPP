#include <iostream>
using namespace std;
#include <vector>
void printVector(vector<vector<int>> vec)
{
    for (auto main : vec)
    {
        for (auto val : main)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int *mult(vector<vector<int>> m1, int row1, int col1, vector<vector<int>> m2, int row2, int col2)
{
    if (col1 != row2)
    {
        return 0;
    }
    // matrix initilisation
    vector<vector<int>> m3(row1, vector<int>(col2, 0));
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            int sum = 0;
            for (int k = 0; k < col1; k++)
            {
                sum += (m1[i][k] * m2[k][j]);
            }
            m3[i][j] = sum;
        }
    }
    printVector(m3);
    return 0;
}
int main()
{
    vector<vector<int>> m1 =
        {
            {10, 0, 0},
            {0, 1, 20}};
    vector<vector<int>> m2 =
        {
            {10, 1, 1, 1},
            {20, 1, 1, 1},
            {3, 2, 0, 30}};

    mult(m1, m1.size(), m1[0].size(), m2, m2.size(), m2[0].size());
}