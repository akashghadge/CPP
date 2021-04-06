#include "iostream"
bool isPowerofTwo(long long n)
{

    // Your code here
    // for only 2's power n & n-1 is zero so
    if (n == 0)
    {
        return false;
    }
    return !(n & (n - 1));
}