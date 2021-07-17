/*
Given an array of distinct elements which was initially sorted. This array is rotated at some unknown point. The task is to find the minimum element in the given sorted and rotated array. 

Example 1:

Input:
N = 10
arr[] = {2,3,4,5,6,7,8,9,10,1}
Output: 1
Explanation: The array is rotated 
once anti-clockwise. So minium 
element is at last index (n-1) 
which is 1.
Example 2:

Input:
N = 5
arr[] = {3,4,5,1,2}
Output: 1
Explanation: The array is rotated 
and the minimum element present is
at index (n-2) which is 1.
Your Task:
The task is to complete the function minNumber() which takes the array arr[] and its starting and ending indices (low and high) as inputs and returns the minimum element in the given sorted and rotated array.

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN).

Constraints:
1 <= N <= 107
1 <= arr[i] <= 107


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int nums[], int low, int high)
    {
        // Your code here
        int N = high;
        int l = low;
        int h = N;
        int m = 0;
        int ANS = 0;
        if (nums[l] < nums[h])
        {
            return nums[0];
        }
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (m > 0 && nums[m] < nums[m - 1])
            {
                return nums[m];
            }
            if (m < N - 1 && nums[m] > nums[m + 1])
            {
                return nums[m + 1];
            }
            else if (nums[m] > nums[h])
            {
                l = m + 1;
            }
            else
            {
                ANS = m;
                h = m - 1;
            }
        }
        return nums[ANS];
    }
};
int main()
{
    FAST;

    return 0;
}