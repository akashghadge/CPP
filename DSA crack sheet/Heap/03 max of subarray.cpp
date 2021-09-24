/*
Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10 
3rd contiguous subarray = {10 7 9 4}, Max = 10 
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, Max = 15 
6th contiguous subarray = {4 15 12 90}, Max = 90 
7th contiguous subarray = {15 12 90 13}, Max = 90 

Your Task:  
You don't need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N, and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Constraints:
1 ≤ N ≤ 106
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 106


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Sol
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        // your code here
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && arr[i] >= arr[q.back()])
                q.pop_back();
            q.push_back(i);
        }

        for (int i = k; i < n; i++)
        {
            ans.push_back(arr[q.front()]);
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop_front();
            }
            while (!q.empty() && arr[i] >= arr[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        return ans;
    }
};
int main()
{
    FAST;

    return 0;
}