#include <iostream>
using namespace std;
int num;
int factrorial(int num);
int main()
{
    cout << factrorial(10);
}
int factrorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num * factrorial(num - 1);
}