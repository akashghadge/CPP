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
        int arr1[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        int one_index = 0;
        int zero_index = 0;
        int two_index = size - 1;

        for (i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                arr1[zero_index] = 0;
                zero_index++;
            }
            else if (arr[i] == 2)
            {
                arr1[two_index] = 2;
                two_index--;
            }
        }
        for (i = zero_index; i <= two_index; i++)
        {
            arr1[i] = 1;
        }
        cout << "THE CONTAINES OF THE ARRAY" << endl;

        for (i = 0; i < size; i++)
        {
            cout << arr1[i] << endl;
        }
    }
}