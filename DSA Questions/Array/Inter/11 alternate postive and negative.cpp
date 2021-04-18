#include <iostream>
using namespace std;
#include <algorithm>

// here order is not important if important we can not do this solution in o(n) time
// so we firstly differentiate positive and negative first
// and then add one by one negative to each second place upto we found end

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " Max is " << arr[i] << endl;
    }
}
int alternative(int *arr, int size)
{
    int end = size - 1;
    int i = 0;
    while (i < size)
    {
        if (end == i)
        {
            break;
        }
        if (arr[i] < 0)
        {
            swap(arr[i], arr[end]);
            end--;
            continue;
        }
        i++;
    }
    end++;
    printArray(arr, size);
    cout << "After sepration" << endl;

    for (int i = 1; i < size; i = i + 2)
    {
        if (arr[end] < 0)
        {
            swap(arr[end], arr[i]);
            end++;
        }
    }

    printArray(arr, size);
}

int main()
{
    int arr[] = {
        1,
        -1,
        -2, 2, -3, 3, 3, 3, -3, -3, -2, -2, -2, -4, -4, -4, -4};
    int size = sizeof(arr) / sizeof(arr[0]);
    alternative(arr, size);
}