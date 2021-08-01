/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    stack<int> start;
    stack<int> end;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (start.size() == 0 && intervals[i][1] > start.top())
        {
            start.push(intervals[i][0]);
            end.push(intervals[i][1]);
        }
        else
        {
            end.pop();
            end.push(intervals[i][1]);
        }
    }
    intervals.clear();
    while (!start.empty() && !end.empty())
    {
        vector<int> temp;
        temp.push_back(start.top());
        temp.push_back(end.top());
        intervals.push_back(temp);
        start.pop();
        end.pop();
    }
    return intervals;
}
class Solution
{
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //      vector<vector<int>> vect;
    //     if(intervals.size()==1){
    //         return intervals;
    //     }
    //     sort(intervals.begin(), intervals.end());
    //     int a = intervals[0][0];
    //     int b = intervals[0][1];
    //     for(int j = 1; j < intervals.size(); j++){
    //         if(intervals[j][0] <= b){
    //             b = max(b,intervals[j][1]);
    //         }else{
    //             vect.push_back({a,b});
    //             a = intervals[j][0];
    //             b = intervals[j][1];
    //         }
    //     }
    //     vect.push_back({a,b});
    //     return vect;
    // }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        stack<int> start;
        stack<int> end;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            if (start.size() == 0 || intervals[i][0] > end.top())
            {
                start.push(intervals[i][0]);
                end.push(intervals[i][1]);
            }
            else
            {
                int temp = end.top();
                end.pop();
                end.push(max(intervals[i][1], temp));
            }
        }
        intervals.clear();
        while (!start.empty() && !end.empty())
        {
            vector<int> temp;
            temp.push_back(start.top());
            temp.push_back(end.top());
            intervals.push_back(temp);
            start.pop();
            end.pop();
        }
        reverse(intervals.begin(), intervals.end());
        return intervals;
    }
};
int main()
{
    FAST;

    return 0;
}