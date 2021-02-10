#include <iostream>
using namespace std;

template <class T>
class Base
{
public:
    Base()
    {
        cout << "Constructor invoked" << endl;
    }
    Base(int a)
    {
        cout << "Constructor without parameter" << endl;
    }
    T sum(int a, int b)
    {
        return a + b;
    }
};
int main()
{
    Base<int> base;
    cout << base.sum(2, 3);
}