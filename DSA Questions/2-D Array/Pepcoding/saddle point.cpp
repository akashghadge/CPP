// every matirx eithere have one saddle point or do not have
// but there is no 2 saddle points in matrix
// saddle point means element which is lowest in row and hightest in column
#include <iostream>
using namespace std;
#include <vector>
int saddle(vector<vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
    {
        int sIndex = 0;
        int sELme = INT8_MAX;
        for (int j = 0; j < m[i].size(); j++)
        {
            if (sELme > m[i][j])
            {
                sIndex = j;
                sELme = m[i][j];
            }
        }
        bool f = true;
        for (int k = 0; k < m.size(); k++)
        {
            if (m[i][sIndex] < m[k][sIndex])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            return m[i][sIndex];
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 2, 9}};
    cout << saddle(m);
}