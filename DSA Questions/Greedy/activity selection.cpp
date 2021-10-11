/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.

Your Task :
You don't need to read input or print anything. Your task is to complete the function activityselection() which takes array start[ ], array end[ ] and integer N as input parameters and returns the maximum number of activities that can be done.


Expected Time Complexity : O(N * Log(N))
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 2*105
1 ≤ start[i] ≤ end[i] ≤ 109


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
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Your code here
    vector<pair<int, int>> act;
    for (int i = 0; i < n; i++)
    {
        act.push_back({start[i], end[i]});
    }

    sort(act.begin(), act.end(), [](pair<int, int> p1, pair<int, int> p2)
         {
             if (p1.second == p2.second)
             {
                 return p1.first > p2.first;
             }
             return p1.second < p2.second;
         });
    int time_limit = act[0].second;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (time_limit < act[i].first)
        {
            c++;
            time_limit = act[i].second;
        }
    }
    return c;
}
int main()
{
    FAST;

    return 0;
}