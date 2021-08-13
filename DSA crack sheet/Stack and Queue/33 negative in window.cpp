/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
1 <= A[i] <= 105
1 <= K <= N


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    deque<ll> Di;
    vector<ll> ans;
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
            ans.push_back(arr[Di.front()]);

        // else the window does not have a
        // negative integer
        else
            ans.push_back(0);

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front(); // Remove from front of queue

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
            Di.push_back(i);
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
        ans.push_back(arr[Di.front()]);
    else
        ans.push_back(0);
    return ans;
}
int main()
{
    FAST;

    return 0;
}