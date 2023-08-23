/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        int n = arr.size(), lo = 1, hi = n;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            int cn = 0;
            for (auto val : arr)
            {
                if (val <= mid)
                    cn++;
            }
            if (cn <= mid)
                lo = mid + 1;
            else
                ans = mid, hi = mid - 1;
        }
        return ans;
    }
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0];
        int hare = nums[0];

        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
int main()
{
}