/*
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Example 2:

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any
extra space, modify the given arrays
to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}
 

Your Task:
You don't need to read input or print anything. Complete the function merge() which takes the two arrays arr1[], arr2[] and their sizes n and m, as input parameters. The function does not return anything. Use the given arrays to sort and merge arr1[] and arr2[] in-place. 
Note: The generated output will print all the elements of arr1[] followed by all the elements of arr[2].


Expected Time Complexity: O((n+m)*log(n+m))
Expected Auxiliary Space: O(1)


Constraints:
1 <= N, M <= 5*104
0 <= arr1i, arr2i <= 106


*/

#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// complexity is O(nlogn)  and space is O(n+m);
void merge(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    for (int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr3[n + i] = arr2[i];
    }
    sort(arr3, arr3 + n + m);
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr3[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = arr3[n + i];
    }
}

// complexity is O(n+m)  and space is O(n+m);
void mergeOp(int arr1[], int arr2[], int n, int m)
{
    int res[n + m];
    int i = 0, j = 0;
    int pt = 0;
    while (i != n && j != m)
    {
        if (arr1[i] < arr2[j])
        {
            res[pt] = arr1[i];
            i++;
        }
        else
        {
            res[pt] = arr2[j];
            j++;
        }
        pt++;
    }
    if (i != n)
    {
        while (i != n)
        {
            res[pt] = arr1[i];
            i++;
            pt++;
        }
    }
    if (j != m)
    {
        while (j != m)
        {
            res[pt] = arr2[j];
            j++;
            pt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr1[i] = res[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = res[n + i];
    }
}
void mergeOptimise(long long arr1[], long long arr2[], int n, int m)
{
    //Function to merge the arrays.
    // code here
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k
    // or j is less tha m
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    print(arr1, n);
    print(arr2, m);
    // merge(arr1, arr2, n, m);
    mergeOp(arr1, arr2, n, m);
    print(arr1, n);
    print(arr2, m);

    return 0;
}