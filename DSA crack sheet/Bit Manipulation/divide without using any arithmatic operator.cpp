#include <iostream>
using namespace std;

int divide(long long dividend, long long divisor)
{
    // basic approch would (without bit) subtract divisor from dividend and increment q and return q
    /*
        11
        10

        110

        10
        10

        100
    */
    //    for getting sign
    // int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    // use abs for getting pure value without sign;
    // divisor = divisor);
    // dividend = dividend);
    long long q = 0, temp = 0;

    // now iterate to get closer to dividend
    for (int i = 31; i >= 0; --i)
    {
        if (temp + (divisor << i) <= dividend)
        {
            temp += divisor << i;
            q |= 1LL << 1;
        }
    }
    return q;
}
int main()
{
    cout << divide(9, 3);
}