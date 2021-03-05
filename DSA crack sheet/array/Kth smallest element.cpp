#include <iostream>
using namespace std;
// for this que you have to find the nTH or kTH smallest elemenet in the array in linear time and the o(1) space

// for this you should sort the array in linear time  using quick sort algo
void quick_sort(int *, int, int);
int partition(int *, int, int);
void swap_element(int *a, int *b);
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
    int size;
    cin >> t;
    int k;
    while (t--)
    {
        int i;
        cin >> size;
        cin >> k;
        int arr[size];
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        quick_sort(arr, 0, size);
        printArray(arr, size);
        cout << "THE " << k << "th SMALLEST ELEMENT IS : " << arr[k - 1] << endl;
    }
}

int partion_array(int *arr, int lb, int ub)
{

    int pivot;
    pivot = arr[lb];
    int start = lb;
    int end = ub;
    cout << "THe value of the end is " << end << endl;
    while (start < end)
    {
        while (pivot >= arr[start])
        {
            start++;
        }
        while (pivot < arr[end])
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
void quick_sort(int *arr, int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partion_array(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
void swap_element(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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