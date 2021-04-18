#include <iostream>
using namespace std;
#include <algorithm>
int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " Element is " << arr[i] << endl;
    }
}
// heere we apply this solution in o(nlogn) time and o(1) space
// basically if sum is zero in any subarray then duplicate number is always present there
// we can also solve this problem in o(n) time by save sorting time and use current array as hash map so we can find duplicate element
bool subArrayWithSum0(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        arr[i] = sum;
    }
    sort(arr, arr + size);
    printArray(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1] || arr[i] == 0) //0 case if two elements only present and cancel each other a b then a 0
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        bool res = subArrayWithSum0(arr, size);
        cout << "Res :" << res << endl;
    }
}