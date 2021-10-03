/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function smallestSubsegment() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1<=N<=105
-105<=A[i], K<=105

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
int lenOfLongSubarr(vector<int> arr, int N, int k)
{
    // Complete the function
    unordered_map<int, int> mp;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum == k)
            res = i + 1;
        if (mp.find(sum - k) != mp.end())
        {
            res = max(res, i - mp[sum - k]);
        }
        mp[sum] = i;
    }
    return res;
}

int main()
{
    FAST;
    int N, k;
    cin >> N;
    cin >> k;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << lenOfLongSubarr(arr, N, k) << en;
    return 0;
}