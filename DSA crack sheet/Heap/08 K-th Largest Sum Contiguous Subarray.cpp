/*
Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

Examples: 

Input: a[] = {20, -5, -1} 
         k = 3
Output: 14
Explanation: All sum of contiguous 
subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40} 
         k = 6
Output: -10 
Explanation: The 6th largest sum among 
sum of all contiguous subarrays is -10.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
A brute force approach is to store all the contiguous sums in another array and sort it and print the k-th largest. But in the case of the number of elements being large, the array in which we store the contiguous sums will run out of memory as the number of contiguous subarrays will be large (quadratic order)

An efficient approach is to store the pre-sum of the array in a sum[] array. We can find sum of contiguous subarray from index i to j as sum[j]-sum[i-1] 

Now for storing the Kth largest sum, use a min heap (priority queue) in which we push the contiguous sums till we get K elements, once we have our K elements, check if the element is greater than the Kth element it is inserted to the min heap with popping out the top element in the min-heap, else not inserted. In the end, the top element in the min-heap will be your answer.


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
int kthLargestSum(vector<int> arr, int k)
{
    vector<int> prefix(arr.size() + 1);
    prefix[0] = 0;
    prefix[1] = arr[0];
    for (int i = 2; i <= arr.size(); i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = i; j <= arr.size(); j++)
        {
            int subArraySum = prefix[j] - prefix[i - 1];
            if (pq.size() < k)
            {
                pq.push(subArraySum);
            }
            else
            {
                if (pq.top() < subArraySum)
                {
                    pq.pop();
                    pq.push(subArraySum);
                }
            }
        }
    }
    return pq.top();
}
int main()
{
    FAST;
    vector<int> arr = {10,
                       -10,
                       20,
                       -40};
    cout << kthLargestSum(arr, 6) << en;
    return 0;
}