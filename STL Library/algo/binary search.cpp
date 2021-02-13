#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class arrT>
void showArr(arrT arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "Element at " << i << " index is :" << arr[i] << endl;
    }
}

int main()
{
    int nums[] = {1, 3, 4, 6, 7, 9};
    char chars[] = {'a', 'k', 'a', 's', 'h'};
    int arrSize = sizeof(nums) / sizeof(nums[0]);
    int arrCsize = sizeof(chars) / sizeof(chars[0]);
    cout << sizeof(chars[0]) << endl;
    cout << sizeof(nums[0]) << endl;

    showArr(nums, arrSize);
    // binrary search takes prameter from start pointer and end pointer and value which will compare
    // array must be sorted
    if (binary_search(&nums[0], nums + arrSize, 3))
    {
        cout << "is present" << endl;
    }
}