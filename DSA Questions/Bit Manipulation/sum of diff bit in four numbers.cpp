#include <iostream>
using namespace std;
int numberOfDiff(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < 31; i++)
    {
        int mask = 1 << i;
        int set_bits = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] & (mask))
            {
                set_bits++;
            }
        }
        sum += (set_bits) * (size - set_bits) * 2;
    }
    return sum;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << numberOfDiff(arr, size);
}