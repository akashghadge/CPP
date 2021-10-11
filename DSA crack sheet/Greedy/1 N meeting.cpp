/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105


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
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> meet;
    for (int i = 0; i < n; i++)
    {
        meet.push_back(make_pair(start[i], end[i]));
    }
    sort(meet.begin(), meet.end(), [](pair<int, int> i1, pair<int, int> i2)
         { return (i1.second < i2.second); });
    // 
    // initial meeting
    int time_limit = meet[0].second;
    int counter = 1;
    for (int i = 1; i < n; i++)
    {
        if (meet[i].first > time_limit)
        {
            time_limit = meet[i].second;
            counter++;
        }
    }
    return counter;
}
int main()
{
    FAST;

    return 0;
}