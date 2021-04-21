#include <iostream>
using namespace std;
// here you have array of 0 to N-1 numbers no one is missing and duplicate
// just make inverse of it
// i.e  for if at 0 index if 3 is presend then in inverse at 3 index 0 is present
int inverse(int *arr, int size)
{
    int inv[size];
    for (int i = 0; i < size; i++)
    {
        inv[arr[i]] = i;
    }
    for (int i = 0; i < size; i++)
    {
        cout << inv[i] << " ";
    }
    cout << endl;
}
// int inverseOp(int *arr, int size)
// {
//     int v = arr[0];
//     int index = 0;
//     for (int i = 0; i < size; i++)
//     {
//         int ti = arr[v];
//         int tv = arr[ti];
//         arr[v] = index;
//         v = tv;
//         index = ti;
//     }
//     // arr[v] = index;
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
int main()
{
    int arr[] = {3,
                 4,
                 1,
                 2,
                 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    inverse(arr, size);
    // inverseOp(arr, size);
}