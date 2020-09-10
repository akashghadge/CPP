#include <iostream>
using namespace std;
void merge(int *arr, int lb, int mid, int ub, int *array);
void merge_sort(int *arr, int lb, int ub, int *result);
int main()
{
    int size = 5;
    // cin >> size;
    int arr[size];
    int array[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE NO IN THE ARRAY AT THE POSITION " << i << " :" << endl;
        cin >> arr[i];
    }
    merge_sort(arr, 0, size, array);
    cout << "HELLO WORLD" << endl;
    for (i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void merge_sort(int *arr, int lb, int ub, int *result)
{

    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid, result);
        merge_sort(arr, mid + 1, ub, result);
        merge(arr, lb, mid, ub, result);
    }
}
void merge(int *arr, int lb, int mid, int ub, int *array)
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
        array[i] = arr[i];
    }
}