#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
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
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}