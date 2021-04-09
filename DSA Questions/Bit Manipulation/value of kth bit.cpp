#include <iostream>
using namespace std;

// just find value of kth bit either zero or 1

int valueOfKthBit(int n, int k)
{
    int mask = 1 << k - 1;
    if (mask & n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << valueOfKthBit(10, 5) << endl;
}