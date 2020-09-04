#include <iostream>
using namespace std;
void isDuplicate(int *arr, int size, int k);

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
    int k;
    cout << "PLEASE ENTER THE VALUE OF THE K " << endl;
    cin >> k;

    isDuplicate(arr, size, k);
}
void isDuplicate(int *arr, int size, int k)
{
    int i = 0;
    int j = i + 1;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << arr[i] << " AT THE " << i << " POSITION AND THE " << arr[j] << " AT THE " << j << " POSITION HAVE THE SUM " << k << endl;
            }
        }
    }
}