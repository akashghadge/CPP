/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/

// here approch is very easy use extra space for preprocessing of array from left and right side
#include <iostream>
using namespace std;
#include <vector>
int trap(vector<int> &height)
{
    if (height.size() == 0)
        return 0;
    vector<int> leftH(height.size());
    vector<int> rightH(height.size());

    int n = height.size();
    int maxH = height[0];
    for (int i = 0; i < n; i++)
    {
        maxH = max(height[i], maxH);
        leftH[i] = maxH;
    }
    maxH = height[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        maxH = max(height[i], maxH);
        rightH[i] = maxH;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = min(rightH[i], leftH[i]);
        int curr = height[i];
        sum += (diff - curr);
    }
    return sum;
}
int main()
{
}