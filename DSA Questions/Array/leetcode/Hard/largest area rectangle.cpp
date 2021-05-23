/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> lb(n);
        vector<int> rb(n);
        stack<int> st;
        //         for lb this
        st.push(0);
        lb[0] = -1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                lb[i] = -1;
            }
            else
            {
                lb[i] = st.top();
            }
            st.push(i);
        }
        //         clear stack for next step
        while (!st.empty())
        {
            st.pop();
        }
        // cout<<"hello"<<endl;
        //         for rb
        st.push(n - 1);
        rb[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                rb[i] = n;
            }
            else
            {
                rb[i] = st.top();
            }
            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i] * (rb[i] - lb[i] - 1);
            maxA = max(maxA, curr);
        }
        return maxA;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}