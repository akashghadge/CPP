#include <iostream>
using namespace std;
void isDuplicate(int *arr, int size);

int main()
{
    int size = 10;
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE FOR THE " << i << endl;
        cin >> arr[i];
    }
    isDuplicate(arr, size);
}
void isDuplicate(int *arr, int size)
{
    int i = 0;
    int j = i + 1;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " AT THE " << i << " POSITION AND THE " << arr[j] << " AT THE " << j << " POSITION ARE SAME ." << endl;
            }
        }
    }
}