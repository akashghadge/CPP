#include <iostream>
using namespace std;
#include "stack"
stack<int> st;
void PrintBit(int n)
{
    while (n)
    {
        st.push((n & 1));
        n = n >> 1;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int swapN(int x)
{
    return ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
}
int main()
{
    int swapD = swapN(100);
    cout << "Number is :" << swapD << endl;

    return 0;
}
