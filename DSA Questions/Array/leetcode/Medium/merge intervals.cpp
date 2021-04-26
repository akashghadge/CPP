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
vector<vector<int>> mergeIn(vector<vector<int>> intervals)
{
    vector<vector<int>> vect;
    if (intervals.size() == 1)
    {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    int a = intervals[0][0];
    int b = intervals[0][1];
    for (int j = 1; j < intervals.size(); j++)
    {
        if (intervals[j][0] <= b)
        {
            b = max(b, intervals[j][1]);
        }
        else
        {
            vect.push_back({a, b});
            a = intervals[j][0];
            b = intervals[j][1];
        }
    }
    vect.push_back({a, b});
    return vect;
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