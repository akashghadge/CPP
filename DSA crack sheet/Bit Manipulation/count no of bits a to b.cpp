#include <iostream>
using namespace std;
int countBitsFlip(int a, int b)
{

    // Your logic here
    int result = a ^ b;
    int c = 0;
    while (result)
    {
        result = result & (result - 1);
        c++;
    }
    return c;
}
int main()
{
}