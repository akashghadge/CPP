#include <iostream>
using namespace std;

int a = 0;
int partion(int arr[], int lb, int ub)
{
    a++;
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
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
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[end], arr[lb]);
    return end;
}
int quickSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int part = partion(arr, lb, ub);
        quickSort(arr, lb, part - 1);
        quickSort(arr, part + 1, ub);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 2, 6, 7, 8, 5, 4};
    int size = 9;
    quickSort(arr, 0, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Number of Calls " << a << endl;
}