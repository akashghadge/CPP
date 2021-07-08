/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (between 00 to 59).


Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)



*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    // int platform[2500] = {0};
    // int requiredPlatform = 1;
    // for (int i = 0; i < n; i++) {

    //     // increment the platforms for arrival
    //     ++platform[arr[i]];

    //      // once train departs we decrease the platform count
    //     --platform[dep[i] + 1];
    // }

    // // We are running loop till 2361 because maximum time value
    // // in a day can be 23:60
    // for (int i = 1; i < 2500; i++) {

    //     // taking cumulative sum of platform give us required
    //     // number of platform fro every minute
    //     platform[i] = platform[i] + platform[i - 1];
    //     requiredPlatform = max(requiredPlatform, platform[i]);
    // }
    // return requiredPlatform;
    sort(arr, arr + n);
    sort(dep, dep + n);
    int pf = 1;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= dep[j])
        {
            pf++;
        }
        else
        {
            j++;
        }
    }
    return pf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}