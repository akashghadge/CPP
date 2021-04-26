/*
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000

*/

#include <iostream>
using namespace std;
#include <vector>
int sumOddLengthSubarrays(vector<int> &arr)
{
    int n = arr.size();
    int total_sum = 0;
    for (int k = 1; k <= n; k += 2)
    {
        int sum = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (j - i + 1 < k)
            {
                sum += arr[j];
            }
            else if (j - i + 1 == k)
            {
                sum += arr[j];
                total_sum += sum;
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return total_sum;
}
int main()
{
}