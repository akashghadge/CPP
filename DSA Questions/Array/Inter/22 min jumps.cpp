#include <iostream>
using namespace std;
// brute force approch
int util(int arr[], int size, int currIndex, int jumps, int *min)
{
    if (jumps > *min)
    {
        return 0;
    }
    if (currIndex >= size)
    {
        if (*min > jumps)
        {
            *min = jumps;
        }
        return 0;
    }
    int currELement = arr[currIndex];
    if (currELement == 0)
    {
        return 0;
    }
    for (int i = 1; i <= currELement; i++)
    {
        util(arr, size, currIndex + i, jumps + 1, min);
    }
}

int minJumps(int arr[], int size)
{
    int min = INT16_MAX;
    util(arr, size, 0, 0, &min);
    return min;
}
int main()
{
    int arr[] = {10, 10, 1, 3, 1, 0, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, size);
}