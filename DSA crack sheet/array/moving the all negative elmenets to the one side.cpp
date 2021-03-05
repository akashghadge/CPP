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
    int pos1 = 0;
    int pos2 = size - 1;
    while (pos1 < pos2)
    {
        if (arr[pos1] >= 0)
        {
            swap_element(&arr[pos1], &arr[pos2--]);
        }
        else
        {
            pos1++;
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