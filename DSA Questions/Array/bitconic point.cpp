/*
Given an array Arr of N elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.

Example 1:

Input: 
N = 9
Arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
Example 2:

Input: 
N = 5
Arr[] = {1, 45, 47, 50, 5}
Output: 50
Explanation: Maximum element is 50.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findMaximum() which takes the array arr[], and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;
int findMaximum(int arr[], int n)
{
    // code here
    int start = 0;
    int end = n - 1;
    int s = arr[start];
    int e = arr[end];

    for (int i = 0; i < n; i++)
    {
        if (start > end)
        {
            return -1;
        }

        if (arr[start] < arr[start + 1])
        {
            start++;
        }
        else
        {
            return arr[start];
        }

        if (arr[end] < arr[end - 1])
        {
            end--;
        }
        else
        {
            return arr[end];
        }
    }
}

// Function to find bitonic point using binary search
int binarySearch(int arr[], int left, int right)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        // base condition to check if arr[mid] is
        // bitonic point or not
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // We assume that sequence is bitonic. We go to
        // right subarray if middle point is part of
        // increasing subsequence. Else we go to left
        // subarray.
        if (arr[mid] < arr[mid + 1])
            return binarySearch(arr, mid + 1, right);
        else
            return binarySearch(arr, left, mid - 1);
    }

    return -1;
}

int main()
{
}