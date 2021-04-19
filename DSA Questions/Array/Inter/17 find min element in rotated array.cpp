#include <iostream>
using namespace std;

int main()
{
}
int util(int arr[], int low, int high)
{
    // rotated at all
    if (high < low)
        return arr[0];

    // If there is only one element left
    if (high == low)
        return arr[low];

    // Find mid
    int mid = low + (high - low) / 2; /*(low + high)/2;*/

    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid + 1] < arr[mid])
        return arr[mid + 1];

    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
        return arr[mid];

    // Decide whether we need to go to left half or right half
    if (arr[high] > arr[mid])
        return util(arr, low, mid - 1);
    return util(arr, mid + 1, high);
}
int findMin(int arr[], int n)
{
    //complete the function here
    return util(arr, 0, n - 1);
}