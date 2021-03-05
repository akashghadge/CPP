// here you have given the height of the tower in the array
// and one integer k which is add or substract from heights of  tower
// you have to find the min diff between the loongest and shortest heights
// height should not be negative and zero

#include <iostream>
using namespace std;
int minDiff(int *, int, int);
void quickSort(int *, int, int);
int partition(int *, int, int);
void swap_element(int *a, int *b)

{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void setArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}
void printArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int k;
        cin >> k;
        int arr[size];
        setArray(arr, size);
        printArray(arr, size);
        quickSort(arr, 0, size);
        printArray(arr, size);
        minDiff(arr, size, k);
    }
}

int minDiff(int arr[], int size, int k)
{
    int i;
    int min;
    int max = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] - k > 0)
        {
            min = arr[i] - k;
            break;
        }
        else if (arr[i] + k > 0)
        {
            min = arr[i] + k;
            break;
        }
    }

    for (i = size - 1; i >= 0; i--)
    {

        if (arr[i] - k > 0)
        {
            max = arr[i] - k;
            break;
        }
        else
        {
            max = arr[i] + k;
            break;
        }
    }

    cout << "Max" << max << endl;
    cout << "Min" << min << endl;
    int result = max - min;
    cout << result << endl;
}

void quickSort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot;
    int start = lb;
    int end = ub;
    pivot = lb;
    while (start < end)
    {
        while (arr[start] < arr[pivot])
        {
            start++;
        }
        while (arr[end] > arr[pivot])
        {
            end--;
        }
        if (start < end)
        {
            swap_element(&arr[end], &arr[start]);
        }
    }
    swap_element(&arr[pivot], &arr[end]);
    return end;
}