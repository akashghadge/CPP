#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int a = 0;
vector<vector<int>> sum3(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int start = 0;
    int middle = start + 1;
    int end = nums.size() - 1;

    while (start < nums.size() - 2)
    {

        middle = start + 1;
        end = nums.size() - 1;
        if (start > 0 && nums[start] == nums[start - 1])
        {
            start++;
            continue;
        }
        while (middle < end)
        {
            // a++;
            int sum = nums[start] + nums[middle] + nums[end];
            // cout << nums[start] << " " << nums[middle] << " " << nums[end] << " " << endl;
            if (sum == 0)
            {
                vector<int> temp;
                temp.push_back(nums[start]);
                temp.push_back(nums[middle]);
                temp.push_back(nums[end]);
                ans.push_back(temp);
                while (middle < end && nums[middle] == nums[middle + 1])
                    middle++;
                while (middle < end && nums[end] == nums[end - 1])
                    end--;
                middle++;
                end--;
            }

            else if (sum <= 0)
            {
                middle++;
            }
            else if (sum > 0)
            {
                end--;
            }
        }

        start++;
    }
    return ans;
}
int main()
{
    vector<int> nums =
        {0, 0, 0, 0};
    // nums.push_back(-1);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(-1);
    // nums.push_back(-4);
    vector<vector<int>>
        ans = sum3(nums);
    for (auto itr : ans)
    {
        for (auto val : itr)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << " counter :" << a;
}