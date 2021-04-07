#include <iostream>
using namespace std;
#include "vector"
int multi(int a, int b)
{
    // using basic approch
    // if (b == 0)
    // {
    //     return 0;
    // }
    // if (b == 1)
    // {
    //     return a;
    // }
    // if (b > 1)
    // {
    //     return a + (a, b - 1);
    // }

    //using the bitwise operator so
    // method is callled as
    int res = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            res += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    return res;
}
int main()
{
    int a = 3;
    int b = 2;
    cout << a * b << endl;
    multi(a, b);
}