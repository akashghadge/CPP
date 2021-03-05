#include <iostream>
using namespace std;
int merge(int *arr1, int *arr2, int size1, int size2);
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
        int size1;
        cin >> size1;
        int arr1[size1];
        int size2;
        cin >> size2;
        int arr2[size2];
        setArray(arr1, size1);
        setArray(arr2, size2);
        printArray(arr1, size1);
        printArray(arr2, size2);
        merge(arr1, arr2, size1, size2);
        cout << "Result" << endl;
        printArray(arr1, size1);
        printArray(arr2, size2);
    }
}

int merge(int *arr1, int *arr2, int size1, int size2)
{
    for (int i = size2 - 1; i >= 0; i--)
    {
        int j, last = arr1[size1 - 1];
        for (j = size1 - 2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }
        if (j != size1 - 2 || last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}