#include <iostream>
using namespace std;
int findPosition(int N)
{
    // code here
    int i = 0;
    int c = 0;
    while (N)
    {
        int temp = N & 1;
        if (c >= 2)
        {
            return -1;
        }
        if (temp != 0)
        {
            c++;
        }
        N = N >> 1;
        i++;
    }
    if (c == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int main()
{
}