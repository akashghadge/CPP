#include <iostream>
using namespace std;
#include <vector>
vector<int> upperT(vector<vector<int>> m)
{
    vector<int> ans;
    for (int i = 0; i < m[0].size(); i++)
    {
        for (int x = i, y = 0; x < m[0].size() && y < m.size(); y++, x++)
        {
            ans.push_back(m[y][x]);
        }
    }
    return ans;
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<int> ans = upperT(m);
    printVector(ans);
}