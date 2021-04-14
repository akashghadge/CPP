#include <iostream>
using namespace std;
int noOfTripletes(int *arr, int size)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        int val = arr[i];
        for (int k = i + 1; k < size; k++)
        {
            val ^= arr[k];
            if (val == 0)
            {
                c += (k - i);
            }
        }
    }
    return c;
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
    cout << noOfTripletes(arr, size);
}