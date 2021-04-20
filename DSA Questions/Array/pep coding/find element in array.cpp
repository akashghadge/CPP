#include <iostream>
using namespace std;

int serch(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,
                 2,
                 4,
                 5,
                 6,
                 7,
                 8,
                 9,
                 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << serch(arr, size, 10);
}