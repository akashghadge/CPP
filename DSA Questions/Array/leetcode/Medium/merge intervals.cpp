#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void printVector(vector<vector<int>> vec)
{
    for (auto val : vec)
    {
        for (int i = 0; i < val.size(); i++)
        {
            cout << val[i] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> mergeIn(vector<vector<int>> res)
{
    sort(res.begin(), res.end());
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i][1] > res[i - 1][1])
        {
            vector<int> temp = {

                res[i - 1][0],
                res[i][1]

            };

            res.erase(res.begin() + i - 1);
            res.erase(res.begin() + i - 1);
            res.insert(res.begin() + i - 1, temp);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res = {
        {1, 3},
        {2, 6},
        {8, 13}};

    res = mergeIn(res);
    printVector(res);
}