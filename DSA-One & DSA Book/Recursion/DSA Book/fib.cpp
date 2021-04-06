#include <iostream>
using namespace std;
int fib(int current, int pre, int steps)
{
    if (steps == 0)
    {
        return 0;
    }
    cout << current << endl;
    fib(current + pre, current, steps - 1);
}
int main()
{
    fib(0, 1, 10);
}