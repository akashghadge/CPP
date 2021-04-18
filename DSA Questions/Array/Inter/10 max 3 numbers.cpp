#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 100, 150, 200, 90, 32, 12, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max[3] = {0, 0, 0};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max[0])
        {
            max[0] = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < max[0] && arr[i] > max[1])
        {
            max[1] = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < max[0] && arr[i] < max[1] && arr[i] > max[2])
        {
            max[2] = arr[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " Max is " << max[i] << endl;
    }
}