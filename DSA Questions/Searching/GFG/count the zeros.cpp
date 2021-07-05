/*
Given an array of size N consisting of only 0's and 1's. The array is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. Find the count of all the 0's.

Example 1:

Input:
N = 12
Arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
Output: 3
Explanation: There are 3 0's in the given array.

Example 2:

Input:
N = 5
Arr[] = {0, 0, 0, 0, 0}
Output: 5
Explanation: There are 5 0's in the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countZeroes() which takes the array of integers arr[] and its size n as input parameters and returns the number of zeroes present in the array.


Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 105
0 <= Arr[i] <= 1

*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
class Solution
{
public:
    int countZeroes(int arr[], int n)
    {
        // code here
        int low = 0;
        int high = n - 1;
        int mid = 0;
        int size = n;
        while (high - low > 1)
        {
            mid = low + (high - low) / 2;
            if (arr[mid] == 1)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (arr[high] == 1)
        {
            return size - high - 1;
        }
        else if (arr[low] == 1)
        {
            return size - low - 1;
        }
        else
        {
            return size;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}