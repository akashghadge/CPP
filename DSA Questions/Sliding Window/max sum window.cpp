/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

 

Example 1:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
 

Example 2:

Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function maximumSumSubarray() which takes the integer k, vector Arr with size N, containing the elements of the array and returns the maximum sum of a subarray of size K.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int maximumSumSubarray(int k, vector<int> &Arr, int N)
{
    // code here
    int maxS = 0;
    int curr = 0;
    for (int i = 0; i < k; i++)
    {
        curr += Arr[i];
    }
    maxS = max(curr, maxS);
    for (int i = k; i < N; i++)
    {
        curr -= Arr[i - k];
        curr += Arr[i];
        maxS = max(curr, maxS);
    }
    return maxS;
}
