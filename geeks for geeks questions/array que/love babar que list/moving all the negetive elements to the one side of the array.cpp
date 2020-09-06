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
        int temp;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        for (i = 0; i < size; i++)
        {
            int j = 0;
            for (j = 0; j < size; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "THE RESULT IS THE :" << endl;
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
}
