/*
Given an array a[ ] of N elements. Consider array as a circular array i.e. element after an is a1. The task is to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed i.e. after any rearrangement of array elements find |a1 – a2| + |a2 – a3| + …… + |an-1 – an| + |an – a1|.

Example 1:

Input:
N = 4
a[] = {4, 2, 1, 8}
Output: 
18
Explanation: Rearrangement done is {1, 8, 
2, 4}. Sum of absolute difference between 
consecutive elements after rearrangement = 
|1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 
7 + 6 + 2 + 3 = 18.
Example 2:

Input:
N = 2
a[] = {10, 12}
Output: 
4
Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function maxSum() that takes array a[ ] and its size N as input parameters and return the maximum sum using above method.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
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

long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    long long sum = 0;
    int ptr = 0;
    while (i < j)
    {
        sum += arr[j] - arr[i];
        if (ptr == 0)
        {
            i++;
            ptr++;
        }
        else
        {
            j--;
            ptr--;
        }
    }
    sum += arr[n / 2] - arr[0];
    return sum;
}
int main()
{
    FAST;

    return 0;
}