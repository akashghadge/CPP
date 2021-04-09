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
        int k;
        int req_count;
        int count = 0;
        cin >> k;
        req_count = size / k;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        int j;
        for (i = 0; i < size; i++)
        {
            for (j = i; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (req_count < count)
            {
                cout << arr[i];
                count = 0;
            }
            else
            {
                count = 0;
            }
        }
    }
}