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
        int arr[size][size];
        int i;
        int j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                cin >> arr[i][j];
                cout << endl;
            }
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        int middle = size / 2;
        j = 0;
        for (i = 0; i < size; i++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        i = size - 1;
        for (j = 1; j < size; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        j = 0;
        for (i = 0; i < size; i++)
        {
            swap(arr[i][j], arr[i][j + size - 1]);
        }

        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}