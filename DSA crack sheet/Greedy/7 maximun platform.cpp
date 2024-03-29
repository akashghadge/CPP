/*
We are given n-platform and two main running railway track for both direction. Trains which needs to stop at your station must occupy one platform for their stoppage and the trains which need not to stop at your station will run away through either of main track without stopping. Now, each train has three value first arrival time, second departure time and third required platform number. We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station.

Examples:

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the DSA Self Paced Course at a student-friendly price and become industry ready.  To complete your preparation from learning a language to DS Algo and many more,  please refer Complete Interview Preparation Course.

In case you wish to attend live classes with experts, please refer DSA Live Classes for Working Professionals and Competitive Programming Live for Students.

Input : n = 3, m = 6 
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
Output : Maximum Stopped Trains = 5
Explanation : If train no. 1 will left 
to go without stoppage then 2 and 6 can 
easily be accommodated on platform 1. 
And 3 and 4 on platform 2 and 5 on platform 3.

Input : n = 1, m = 3
Train no.|Arrival Time|Dept. Time | Platform No.
    1    | 10:00      |  10:30    |    1
    2    | 11:10      |  11:30    |    1
    3    | 12:00      |  12:20    |    1
           
Output : Maximum Stopped Trains = 3
Explanation : All three trains can be easily
stopped at platform 1.
If we start with a single platform only then we have 1 platform and some trains with their arrival time and departure time and we have to maximize the number of trains on that platform. This task is similar as Activity Selection Problem. So, for n platforms we will simply make n-vectors and put the respective trains in those vectors according to platform number. After that by applying greedy approach we easily solve this problem.
Note : We will take input in form of 4-digit integer for arrival and departure time as 1030 will represent 10:30 so that we may handle the data type easily.
Also, we will choose a 2-D array for input as arr[m][3] where arr[i][0] denotes arrival time, arr[i][1] denotes departure time and arr[i][2] denotes the platform for ith train.


*/

// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

// number of platforms and trains
#define n 2
#define m 5

// function to calculate maximum trains stoppage
int maxStop(int arr[][3])
{
    vector<vector<pair<int, int>>> platforms(n + 1);
    for (int i = 0; i < m; i++)
    {
        platforms[arr[i][2]].push_back({arr[i][1], arr[i][2]});
    }
    for (int i = 0; i < n + 1; i++)
    {
        sort(platforms[i].begin(), platforms[i].end(), [](pair<int, int> p1, pair<int, int> p2)
             { return p1.first < p2.first; });
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (platforms[i].size() == 0)
            continue;

        // first train for each platform will
        // also be selected
        int x = 0;
        count++;
        for (int j = 1; j < platforms[i].size(); j++)
        {
            if (platforms[i][j].second >=
                platforms[i][x].first)
            {
                x = j;
                count++;
            }
        }
    }
    return count;
}

// driver function
int main()
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}
