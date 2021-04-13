#include <iostream>
using namespace std;
int nOfSetBit(long n);
long ncr(long n, long r)
{
    if (r > n)
    {
        return 0;
    }
    else if (r == n || r == 0)
    {
        return 1;
    }
    long res = 1L;
    for (long i = 0L; i < r; i++)
    {
        res = res * (n - 1);
        res = res / (i + 1);
    }
    return res;
}
long util(long n, int nSetBit, int posBit)
{
    if (posBit < 0)
    {
        return 0;
    }
    long mask = 1L << posBit;
    long res = 0;
    if ((mask & n) == 0)
    {
        res = util(n, nSetBit, posBit - 1);
    }
    else
    {
        long res1 = util(n, nSetBit - 1, posBit - 1);
        long res0 = ncr(posBit, nSetBit);
        res = res1 + res0;
    }
    return res;
}
long sol(long n)
{
    int nSetBit = nOfSetBit(n);
    return util(n, nSetBit, 63);
}
int nOfSetBit(long n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c++;
}
int main()
{
    long n;
    cin >> n;
    long ans = sol(n);
    cout << ans;
}