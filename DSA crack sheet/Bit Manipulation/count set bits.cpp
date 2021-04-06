#include <iostream>
using namespace std;
int setBits(int N)
{
    int c = 0;
    if (N == 0)
    {
        return 0;
    }
    while (N)
    {
        N = N & (N - 1);
        c++;
    }
    return c;
}
int main()
{
}