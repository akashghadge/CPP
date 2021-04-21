#include <iostream>
using namespace std;
int reverseArrayRange(int *arr, int i, int j)
{
    int l1 = i;
    int r1 = j;
    while (l1 < r1)
    {
        swap(arr[l1], arr[r1]);
        l1++;
        r1--;
    }
}
int rotate(int *arr, int size, int k)
{
    // for getting larger values of k
    k = k % size;
    if (k < 0)
    {
        k = k + size;
    }
    // part1
    reverseArrayRange(arr, 0, size - k - 1);
    // part2
    reverseArrayRange(arr, size - k, size - 1);
    // all array
    reverseArrayRange(arr, 0, size - 1);
    return 0;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int k;
    cin >> k;
    rotate(arr, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}