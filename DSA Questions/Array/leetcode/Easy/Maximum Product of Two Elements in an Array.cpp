/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int maxProduct(vector<int> &nums)
{
    // time O(nlogn);
    // int maxS = 0;
    if (nums.size() <= 1)
    {
        return 0;
    }
    // sort(nums.begin(), nums.end());
    // return ((nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1));

    //         without sorting approch
    int first = 0, second = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (first < nums[i])
        {
            second = first;
            first = nums[i];
        }
        // if max element is repetedi first>=num
        else if (first >= nums[i] && second < nums[i])
        {
            second = nums[i];
        }
    }
    return (first - 1) * (second - 1);
}
int main()
{
    vector<int> nums = {3, 4, 5, 2};
    cout << maxProduct(nums);
}