#include <iostream>
using namespace std;
// always add parenthesis for bit operations
int firstDiffBit(int a, int b)
{
    for (int i = 0; i < 31; i++)
    {
        // printf("%d %d\n", a & 1, b & 1);
        if (!(((a & 1) == 0 && (b & 1) == 0) || (a & 1 == 1 && b & 1 == 1)))
        {
            // cout << (a & 1) << (b & 1) << endl;

            return i + 1;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return -1;
}
int main()
{
    cout << firstDiffBit(10, 10) << endl;
}