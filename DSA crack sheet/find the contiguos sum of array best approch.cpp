// test case
// no of elemeent
// array elemenets

// it can be solved using the kadens algo
#include <iostream>
using namespace std;
int maxNumber(int *arr, int);
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
        int arr[size];
        setArray(arr, size);
        printArray(arr, size);
        int result = maxNumber(arr, size);
        cout << "The max number is the :" << result << endl;
    }
}

int maxNumber(int *arr, int size)
{
    int max = INT32_MIN, current = 0;
    for (int i = 0; i < size; i++)
    {
        current += arr[i];
        if (max < current)
            max = current;
        if (current < 0)
            current = 0;
    }
    return max;
}