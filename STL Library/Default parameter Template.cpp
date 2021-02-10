#include <iostream>
using namespace std;

// you can set the default data types
template <class T1 = int, class T2 = int>
class Add
{
public:
    T1 data1;
    T2 data2;
    Add(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << "The sumation is the :" << data1 + data2 << endl;
    }
};

int main()
{
    // here we should must add triangel brackets
    Add<> a(2, 3);
    a.display();

    // it always applay one parameter for the first parameter
    Add<float> b(2.3, 3);
    b.display();

    // this will also apply for the first parameter
    Add<float> c(2, 3.3);
    c.display();

    Add<char, int> d('a', 3);
    d.display();
}