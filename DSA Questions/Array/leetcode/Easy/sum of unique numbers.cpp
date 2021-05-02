/*
You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

Return the sum of all the unique elements of nums.

 

Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
Example 3:

Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

#include <iostream>
using namespace std;
#include <vector>
int sumOfUnique(vector<int> &nums)
{
    // unordered_map<int,int> mp;
    // for(auto val:nums)
    // {
    //     mp[val]++;
    // }
    // int sum=0;
    // for(auto val : mp)
    // {
    //     if(val.second==1)
    //     {
    //         sum+=val.first;
    //     }
    // }
    // return sum;

    int sum = 0;
    vector<bool> v(100, 0);
    vector<bool> f(100, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (v[nums[i]] == false)
        {
            sum += nums[i];
            v[nums[i]] = true;
        }
        else
        {
            if (f[nums[i]] == false)
            {
                sum -= nums[i];
                f[nums[i]] = true;
            }
        }
    }
    return sum;
}   
int main()
{
}