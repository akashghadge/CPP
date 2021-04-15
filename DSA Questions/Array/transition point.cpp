/*
Given a sorted array containing only 0s and 1s, find the transition point. 


Example 1:

Input:
N = 5
arr[] = {0,0,0,1,1}
Output: 3
Explanation: index 3 is the transition 
point where 1 begins.

Example 2:

Input:
N = 4
arr[] = {0,0,0,0}
Output: -1
Explanation: Since, there is no "1",
the answer is -1.

Your Task:
You don't need to read input or print anything. The task is to complete the function transitionPoint() that takes array and N as input parameters and returns the 0 based index of the position where "0" ends and "1" begins. If array does not have any 1s, return -1. If array does not have any 0s, return 0.


Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)


*/

#include <iostream>
using namespace std;
int first(int arr[], int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
        {
            return mid;
        }
        if (arr[mid] == 0)
        {
            return first(arr, mid + 1, end);
        }
        else
        {
            return first(arr, start, mid - 1);
        }
    }
    return -1;
}

int transitionPoint(int arr[], int n)
{
    // code here
    return first(arr, 0, n - 1);
}
int main()
{
}