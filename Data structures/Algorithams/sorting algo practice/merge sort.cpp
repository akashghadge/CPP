#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
    Merge sort is basically divide and conq. algo
    here we can say that we divide the array in small chunks and then merge then by
    comparing chunks elements one by one
    i.e
                    1 4 3 2
                1   4    3     2
                1 4        2 3
                1 2 3 4
*/
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int Merge(vector<int> &arr, int lb, int mid, int ub, vector<int> &result)
{
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[lb + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;  // Initial index of first subarray
    j = 0;  // Initial index of second subarray
    k = lb; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    for (i = 0; i < ub; i++)
    {
        result[i] = arr[i];
    }
}
int MergeSort(vector<int> &arr, int lb, int ub, vector<int> &result)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MergeSort(arr, lb, mid, result);
        MergeSort(arr, mid + 1, ub, result);
        Merge(arr, lb, mid, ub, result);
    }
}
int main()
{
    /* intial setup */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* array input*/
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> res(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    printVector(arr);
    MergeSort(arr, 0, arr.size(), res);
    printVector(res);
}