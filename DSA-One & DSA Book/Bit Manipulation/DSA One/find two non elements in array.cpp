#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 100, 100, 2, 1};
    int result = arr[0];
    int x = 0;
    int y = 0;
    for (int i = 1; i < 7; i++)
    {
        result = arr[i] ^ result;
    }
    int set_bit_no = result & ~(result - 1);
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] & set_bit_no)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }

    printf("%d\n%d", x, y);
}