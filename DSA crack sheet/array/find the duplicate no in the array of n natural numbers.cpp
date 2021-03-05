#include <iostream>
using namespace std;

int duplicate(int *, int);
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
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
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
        int arr[size];
        setArray(arr, size);
        printArray(arr, size);
        quickSort(arr, 0, size);
        printArray(arr, size);
        int result = duplicate(arr, size);
        cout << "Result : " << result << endl;
    }
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
    pivot = arr[lb];
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap_element(&arr[start], &arr[end]);
        }
    }
    swap_element(&arr[lb], &arr[end]);
    return end;
}

int duplicate(int *arr, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
            break;
        }
    }
}