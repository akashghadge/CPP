/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

#include <iostream>
using namespace std;
#include <vector>
// here as we now area=dist(j-i)*minLenghtContainer
// so for this brute force is check for each pair of vertical lines
// and second option is move vertical line if it is lesser then other
int maxArea(vector<int> &height)
{
    // vector<int> left;
    // vector<int> right;
    // int max=0;
    // for(auto val:height){
    //     if(max<val){
    //         max=val;
    //     }
    //     left.push_back(max);
    // }
    // max=0;
    // for(int i=height.size()-1;i>=0;i--){
    //     if(max<height[i]){
    //         max=height[i];
    //     }
    //     right.push_back(max);
    // }
    // reverse(right.begin(),right.end());
    // int maxArea=0;

    // for(int i=0;i<height.size();i++)
    // {
    //     for(int j=height.size()-1;j>i;j--)
    //     {
    //         int dist=j-i;
    //         int minH=min(height[i],height[j]);
    //         int currArea=minH*dist;
    //         if(currArea>maxArea){
    //             maxArea=currArea;
    //         }
    //     }
    // }
    // return maxArea;
    int i = 0;
    int j = height.size() - 1;
    int maxArea = 0;
    while (i < j)
    {
        int minH = min(height[i], height[j]);
        maxArea = max(maxArea, (j - i) * minH);
        height[i] > height[j] ? j-- : i++;
    }
    return maxArea;
}
int main()
{
}