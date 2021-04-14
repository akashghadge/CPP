#include <iostream>
using namespace std;
#include "vector"
int getRev(int n)
{
    int ans = 0;
    int i = 0;
    while (n)
    {
        int mask = n & 1;
        ans |= mask;
        ans = ans << 1;
        n = n >> 1;
    }
    return ans;
}

int palindromeBinary(int n)
{
    int grpNo = 1;
    int count = 1;
    while (count < n)
    {
        grpNo++;
        count += (1 << ((grpNo - 1) / 2));
    }
    count -= (1 << (grpNo - 1) / 2);
    int offset = n - count - 1;

    int ans = 1;

    ans |= (1 << (grpNo - 1));
    ans |= (offset << (grpNo / 2));
    int val = ans >> (grpNo / 2);
    int rev = getRev(val);

    ans |= rev;
    return ans;
}
int main()
{
    cout << palindromeBinary(2);
}