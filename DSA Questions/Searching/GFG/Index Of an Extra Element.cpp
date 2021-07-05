/*
Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. First array has one element extra added in between. Find the index of the extra element.

Example 1:

Input:
N = 7
A[] = {2,4,6,8,9,10,12}
B[] = {2,4,6,8,10,12}
Output: 4
Explanation: In the second array, 9 is
missing and it's index in the first array
is 4.
Example 2:

Input:
N = 6
A[] = {3,5,7,9,11,13}
B[] = {3,5,7,11,13}
Output: 3
Your Task:
You don't have to take any input. Just complete the provided function findExtra() that takes array A[], B[] and size of A[] and return the valid index (0 based indexing).

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
2<=N<=104
1<=Ai<=105


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int findExtra(int a[], int b[], int n)
{
    // add code here.
    int mid, low = 0, high = n - 1;
    int index = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == b[mid])
        {
            low = mid + 1;
        }
        else
        {
            index = mid;
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}