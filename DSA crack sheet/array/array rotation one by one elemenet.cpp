#include <iostream>
using namespace std;

void rotate_by_1(int *, int);
void rotate(int *, int, int);
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
        printArray(arr, size);
        rotate(arr, size, 2);
        printArray(arr, size);
    }
}

void rotate_by_1(int *arr, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        swap_element(&arr[i], &arr[i + 1]);
    }
}

void rotate(int *arr, int size, int d)
{
    int i;
    for (i = 0; i < size; i = i + d)
    {
        int j;
        for (j = i; j <= d; j++)
        {
            swap_element(&arr[j], &arr[j + d]);
        }
    }
}