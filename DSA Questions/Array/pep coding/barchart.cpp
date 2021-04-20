#include <iostream>
using namespace std;
void barchart(int *arr, int size)
{
    int max = INT8_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << max << endl;

    for (int i = max - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] - i > 0)
            {
                cout << "@";
            }
            else
            {
                cout << " ";
            }

            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 8, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    barchart(arr, size);
}