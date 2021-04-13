#include <iostream>
using namespace std;
int util(int num, int operations, int *o)
{
    if (num == 1)
    {
        if (operations < *o)
        {
            *o = operations;
        }
        return 0;
    }
    if (num & 1)
    {
        util(num + 1, operations + 1, o);
        util(num - 1, operations + 1, o);
    }
    else
    {
        util(num >> 1, operations + 1, o);
    }
}

int reduce(int num)
{
    int o = INT8_MAX;
    util(num, 0, &o);
    return o;
}
int main()
{
    cout << reduce(6);
}