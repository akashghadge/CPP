/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 

Follow up: The overall run time complexity should be O(log (m+n)).

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums3;
    if (!nums1.size() && !nums2.size())
    {
        return 0;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        nums3.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        nums3.push_back(nums2[i]);
    }
    sort(nums3.begin(), nums3.end());
    double median = 0;
    int index = nums3.size();
    if (index % 2 == 1)
        median = nums3[index / 2];
    else
        median = (nums3[index / 2] + nums3[index / 2 - 1]) / 2.0;
    return median;
}
int main()
{
}