#include <iostream>
using namespace std;

template <class T>
class Base
{
protected:
    T data;

public:
    Base(T a)
    {
        this->data = a;
        cout << "Constructor invoked" << endl;
    }
    void display();
};

// template line is compulsory
template <class T>
// you can just make the scope resoulation operator as it is
void Base<T>::display()
{
    cout << "display is on " << this->data << endl;
}

// this code for function overloading with templates
/*
here simple function always haave the higher priority
than template function 
*/

template <class a>
void func(a value)
{
    cout << "template func is invoked " << value << endl;
}
void func(int a)
{
    cout << "Simple function is invoked " << a << endl;
}

int main()
{
    Base<int> b(2);
    b.display();
    func('c');
    func(2);
}