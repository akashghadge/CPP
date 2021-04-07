#include <iostream>
using namespace std;

int copyBit(int num1, int num2, int r, int l)
{
    // for this basicaly we need to make mask;
    // firsly make 00...1 binary 1
    int m = 1;
    // left shift it to r-l and +1 time for after -1 we wiilll get all left bits will be 1
    // 000001 -> 010000 -1 ->001111
    m = m << (r - l + 1);
    m--;
    // shift these bits to right for l-1 places
    m = m << (l - 1);
    // get or for mask;
    num1 = num1 & m;
    // get or for getting all zeros to 1 if already there is zero then no need to switch
    return num1 | num2;
}
int main()
{
    cout << copyBit(13, 10, 2, 3);
}