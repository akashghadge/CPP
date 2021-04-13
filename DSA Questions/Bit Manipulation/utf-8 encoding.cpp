#include <iostream>
using namespace std;

bool isUTF(int *arr, int size)
{
    int remB = 0;
    for (int i = 0; i < size; i++)
    {
        if (remB == 0)
        {
            if (arr[i] >> 7 == 0b0)
            {
                remB = 0;
            }
            else if (arr[i] >> 5 == 0b110)
            {
                remB = 1;
            }
            else if (arr[i] >> 4 == 0b1110)
            {
                remB = 2;
            }
            else if (arr[i] >> 3 == 0b11110)
            {
                remB = 3;
            }
        }
        else
        {
            if (arr[i] >> 6 == 0b10)
            {
                remB--;
            }
            else
            {
                return false;
            }
        }
        if (remB == 0)
            return true;
        else
            return false;
    }
}
int main()
{
    int arr[] = {1, 3, 4, 5, 255};
    cout << isUTF(arr, sizeof(arr) / sizeof(arr[0]));
}
