#include "stack"
#include <iostream>
#include "cmath"
using namespace std;

int main()
{
}
int util(stack<int> &s, int sizeOfStack, int currentSize)
{
    // here ceil does round of to closest interger
    if (currentSize == ceil(sizeOfStack / 2.0))
    {
        s.pop();
        return 0;
    }
    int temp = s.top();
    s.pop();
    util(s, sizeOfStack, currentSize - 1);
    s.push(temp);
    return 0;
}
void deleteMid(stack<int> &s, int sizeOfStack)
{
    // code here..
    util(s, sizeOfStack, sizeOfStack);
}