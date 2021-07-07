/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
Accepted
1,045,125
Submissions
2,864,378

*/
/*
 4 5 6 7 8 0 1 2 3
*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            else if (nums[s] <= nums[mid]) //left
            {
                //left check
                if (target >= nums[s] and target < nums[mid])
                {
                    e = mid - 1;
                }
                //right
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] and target <= nums[e])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
int sol(vector<int> &arr, int target)
{
    int hi = arr.size() - 1;
    int lo = 0;
    int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        // increasing graph present  at left side
        else if (arr[mid] >= arr[lo])
        {
            if (target > arr[mid] && target <= arr[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        else
        {
            if (target < arr[mid] and target >= arr[lo])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }
    return -1;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    int N;
    int target;
    while (T--)
    {
        cin >> N >> target;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << sol(arr, target) << en;
    }

    return 0;
}