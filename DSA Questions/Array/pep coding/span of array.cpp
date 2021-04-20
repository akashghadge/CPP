#include <iostream>
using namespace std;
int span(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = INT8_MAX;
    int max = INT8_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max - min;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << span(arr, n);
}