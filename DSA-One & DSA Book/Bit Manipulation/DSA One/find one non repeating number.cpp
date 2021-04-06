#include <iostream>
using namespace std;
// here basicaly one element is non repeting in array 
// so we can use double for also but it will use time o(n^2) and also use hash map but it will use o(n) space
// so this solution will work in o(n) time without any exatra space
// x-or have property when we do xor with same number then it will give result zero
int main()
{
    int arr[] = {1, 2, 3,100,100, 2, 1};
    int result = 0;
    for (int i = 0; i < 7; i++)
    {
        result = arr[i] ^ result;
    }
    printf("%d\n", result);
}