#include <iostream>
using namespace std;

// for less use of space we use the dutch flag algo

void printArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}
void swap_element(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort012(int *arr, int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap_element(&arr[low++], &arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap_element(&arr[mid], &arr[high--]);
            break;

        default:
            break;
        }
    }
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
        int i;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        sort012(arr, size);
        printArray(arr, size);
    }
}