/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
Your Task:
Your task is to complete the function tour() which takes the required data as inputs and returns an integer denoting a point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). If there exists multiple such starting points, then the function must return the first one out of those. (return -1 otherwise)

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)

Constraints:
2 ≤ N ≤ 10000
1 ≤ petrol, distance ≤ 1000


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
struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    /*
    N = 4
    Petrol = 4 6 7 4
    Distance = 6 5 3 5
    balance -2 1 5 4
            2
    */
    //Your code here
    int start = 0;
    int end = (start + 1) % n;
    int balance = p[start].petrol - p[start].distance;
    while (start != end || start == n)
    {
        // cout << "start :" << start << " end :" << end << " bal :" << balance << endl;
        if (balance < 0)
        {
            start = end;
            balance = p[start].petrol - p[start].distance;
        }
        balance += p[end].petrol - p[end].distance;
        end = (end + 1) % n;
    }
    if (start == end)
        return start;
    else
        return -1;
}
int tour(petrolPump arr[], int n)
{
    // Consider first petrol pump as a starting point
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    /* Run a loop while all petrol pumps are not visited.
    And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 && start != end)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;

            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0)
                return -1;
        }

        // Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;

        end = (end + 1) % n;
    }

    // Return starting point
    return start;
}
int main()
{
    FAST;
    int N;
    cin >> N;
    petrolPump p[N];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].petrol;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].distance;
    }

    cout << tour(p, N) << endl;
    return 0;
}