#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int makeChanges(vector<int> &mat, vector<vector<int>> query)
{
    for (auto q : query)
    {
        int a = q[0];
        int b = q[1];
        int val = q[2];
        for (int i = a; i <= b; i++)
        {
            mat[i] += val;
        }
    }
    return *max_element(mat.begin(), mat.end());
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> mat(n, 0);
    vector<vector<int>> query;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        query.push_back(temp);
    }
    cout << makeChanges(mat, query);
}