#include <bits/stdc++.h>
using namespace std;
// here so many approches are possible
// use two loops and find dup in o(n^2)
// use sort and o(n) for all elements O(nlogn)
// use map o(n) and space o(n)
// use current arrray as map due to numbers from 1 to n+1

/*
most optimized
Since all values of the array are between [1…n][1 \dots n][1…n] and the array size is n+1n+1n+1, while scanning the array from left to right, we set the nums[n]\textit{nums}[n]nums[n] to its negative value.
With extra O(1)O(1)O(1) space, with modifying the input.
*/
int findDuplicate_mark(int nums[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int num = nums[i];
        int idx = abs(num);
        if (nums[idx] < 0)
        {
            return idx;
        }
        nums[idx] = -nums[idx];
    }
    return len;
}

int duplicate(int *, int);
void setArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
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
        int result = duplicate(arr, size);
        cout << "Result : " << result << endl;
    }
}

int duplicate(int *arr, int size)
{
    sort(arr, arr + size);
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
            break;
        }
    }
}