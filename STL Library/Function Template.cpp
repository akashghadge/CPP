#include <iostream>
using namespace std;

template <class T1, class T2>
float func(T1 a, T2 b)
{
    return a + b;
}

template <class T>
void swapAny(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    float result = func(1, 2);
    result = func(1, 3.3);
    result = func(1, 'c');
    cout << "Result is :" << result << endl;

    int a = 1;
    int b = 3;
    cout << a << " " << b << endl;
    swapAny(a, b);
    cout << a << " " << b << endl;

    char c1 = 'a';
    char c2 = 'b';
    cout << c1 << " " << c2 << endl;
    swapAny(c1, c2);
    cout << c1 << " " << c2 << endl;
}