#include <iostream>
using namespace std;
#include "vector"
#include <algorithm>
vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum ^= nums[i];
    }
    // here we need right most set bit for comparing both number
    int set_bit = sum & ~(sum - 1);
    /*
        1111
        and
        1110
        for getting rightmost bit zero
        1110
        
        1111
        and 
        not of
        1110
        for getting value of rightmost bit
        0001
        
        
        1010
        1001
        
        0010
        
        */
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set_bit & nums[i])
        {
            x ^= nums[i];
        }
        else
        {
            y ^= nums[i];
        }
    }
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
}