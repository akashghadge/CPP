/*

*/

#include <iostream>
using namespace std;
#include <vector>
vector<int> dup(vector<int> nums)
{

    vector<int> ans;
    // sort(nums.begin(),nums.end());
    // for(int i=1;i<nums.size();i++)
    // {
    //     if(nums[i]==nums[i-1])
    //     {
    //         ans.push_back(nums[i]);
    //     }
    // }
    // return ans;

    //         make current array hashmap
    int n = nums.size();
    if (nums.size() == 1)
    {
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        nums[(nums[i] - 1) % n] = nums[(nums[i] - 1) % n] + n;
    }
    int i = 1;
    for (auto val : nums)
    {
        if (val >= n * 2)
        {
            ans.push_back(i);
        }
        i++;
    }
    return ans;
}
int main()
{
}