/*
Given an array of size N consisting of only 0's and 1's. The array is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. Find the count of all the 0's.

Example 1:

Input:
N = 12
Arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}
Output: 3
Explanation: There are 3 0's in the given array.

Example 2:

Input:
N = 5
Arr[] = {0, 0, 0, 0, 0}
Output: 5
Explanation: There are 5 0's in the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countZeroes() which takes the array of integers arr[] and its size n as input parameters and returns the number of zeroes present in the array.


Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

*/

#include <iostream>
using namespace std;
int firstZero(int arr[], int start, int end)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0)
            return mid;

        if (arr[mid] == 1)
            return firstZero(arr, (mid + 1), end);
        else
            return firstZero(arr, start, (mid - 1));
    }
    return -1;
}
int countZeroes(int arr[], int n)
{
    // code her
    int first = firstZero(arr, 0, n - 1);
    if (first == -1)
    {
        return n;
    }
    else
    {
        return n - first;
    }
}
int main()
{
}