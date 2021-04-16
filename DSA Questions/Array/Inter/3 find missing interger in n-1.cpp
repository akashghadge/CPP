#include <iostream>
using namespace std;

int missing(int *arr, int n)
{
    int sum = 0;
    int sumN = 1;
    for (int i = 0; i < n; i++)
    {
        sum ^= arr[i];
        sumN ^= i + 2;
    }
    return sum ^ sumN;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int size = 4;
    cout << missing(arr, size);
}