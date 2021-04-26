/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 105
All the integers in rating are unique.

*/

// here brute force approch is use 3 loop in it i.e o(n^3)
// and optimise one is we follow here approch like permutations
// we count lesser and greater numbers on both side and then mutliply then for all posible possibilities
#include <iostream>
using namespace std;
#include <vector>
int numTeams(vector<int> &rating)
{
    int n = rating.size();
    int teams = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int leftS = 0;
        int leftG = 0;
        int rightS = 0;
        int rightG = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (rating[i] < rating[j])
            {
                leftG++;
            }
            else
            {
                leftS++;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (rating[i] < rating[j])
            {
                rightG++;
            }
            else
            {
                rightS++;
            }
        }
        teams += (leftS * rightG) + (leftG * rightS);
    }
    return teams;
}
int main()
{
}