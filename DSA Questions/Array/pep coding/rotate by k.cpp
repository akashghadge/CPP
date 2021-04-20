#include <iostream>
using namespace std;
int rotate(int *arr, int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        swap(arr[i], arr[(i + k + size) % size]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k;
    cin >> k;
    rotate(arr, 5, k);
}