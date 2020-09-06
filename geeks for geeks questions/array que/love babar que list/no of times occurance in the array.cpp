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
        int target;
        cin >> target;
        int count = 0;
        for (i = 0; i < size; i++)
        {
            if (arr[i] == target)
            {
                count++;
            }
        }
        cout << count;
    }
}