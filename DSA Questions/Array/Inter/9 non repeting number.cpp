#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 100, 100, 2, 1};
    int result = 0;
    for (int i = 0; i < 7; i++)
    {
        result = arr[i] ^ result;
    }
    printf("%d\n", result);
}