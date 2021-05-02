#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
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
void rotate(vector<vector<int>> &m)
{
    // i.e make tranpose and reverse colomuns
    // firstly swap upper traingular with lower one and then reverse it
    for (int i = 0; i < m[0].size(); i++)
    {
        for (int x = i, y = 0; x < m[0].size() && y < m.size(); y++, x++)
        {
            swap(m[x][y], m[y][x]);
        }
    }

    for (int i = 0; i < m.size(); i++)
    {

        for (int j = 0, k = m[0].size() - 1; j < m[0].size() / 2; j++, k--)
        {
            swap(m[i][j], m[i][k]);
        }
    }
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(m);
    printVector(m);
}