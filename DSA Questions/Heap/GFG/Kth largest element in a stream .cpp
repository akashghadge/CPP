/*
Given an input stream arr[] of n integers. Find the Kth largest element for each element in the stream and if the Kth element doesn't exist, return -1.

Example 1:

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.
Example 2:

Input:
k = 1, n = 2
arr[] = {3, 4}
Output:
3 4 
Explanation: 
For the 1st and 2nd element the 1st largest 
element is itself.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes 2 Integers k, and n and also an array arr[] of size n as input and returns the kth largest element in the stream.

 

Expected Time Complexity: O(nlogk)
Expected Auxiliary Space: O(n)

 

Constraints:
1 ≤ k ≤ n ≤ 105
1 ≤ arr[i] ≤ 105


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
vector<int> kthLargest(int k, int arr[], int n)
{
    // code here
    vector<int> res(n, -1);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() == k)
        {
            if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        else
        {
            pq.push(arr[i]);
        }
        pq.size() == k ? res[i] = pq.top() : res[i] = -1;
    }
    return res;
}
int main()
{
    FAST;

    return 0;
}