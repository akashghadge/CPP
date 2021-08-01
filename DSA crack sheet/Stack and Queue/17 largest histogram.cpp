/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 1012


*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> lb(n);
        vector<long long> rb(n);
        stack<long long> st;
        //         for lb this
        st.push(0);
        lb[0] = -1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
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
            while (!st.empty() && arr[st.top()] >= arr[i])
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
        long long maxA = 0;
        for (int i = 0; i < n; i++)
        {
            long long curr = arr[i] * (rb[i] - lb[i] - 1);
            maxA = max(maxA, curr);
        }
        return maxA;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
