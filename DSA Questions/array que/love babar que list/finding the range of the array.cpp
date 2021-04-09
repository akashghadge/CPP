#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        // int count_min = 0;
        // int count_max = 0;
        int j = 0;
        int k = 0;
        for (i = 0; i < size; i++)
        {
            if (arr[i] > arr[j])
            {
                j = i;
            }
            if (arr[i] < arr[k])
            {
                k = i;
            }
        }
        cout << arr[j] - arr[k];
    }
}