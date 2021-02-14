#include <iostream>
using namespace std;
#include "stack"

int main()
{
    stack<int> numStack;
    numStack.push(1);
    numStack.emplace(3);
    cout << numStack.size() << endl;
    while (!numStack.empty())
    {
        int top = numStack.top();
        cout << "stack element :" << top << endl;
        numStack.pop();
    }

    cout << numStack.size() << endl;
}