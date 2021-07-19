/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ L ≤ 104
1 ≤ Arr[i], N ≤ 105


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
bool findPair(int a[], int sz, int n)
{
    //code
    // sort(a, a + sz);
    // int p = 0, q = 1; // two pointers
    // while(q < sz)
    // if(a[q] - a[p] < n) // increase the diff
    // q++;
    // else if(a[q] - a[p] > n) // decrease the diff
    // p++;
    // else return true;
    // return false;

    // using binary search
    sort(a, a + sz);
    for (int i = sz - 1; i >= 0; i--)
    {
        int val = a[i] - n;
        if (binary_search(a, a + sz, val))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}