#include <iostream>
using namespace std;

template <class T1, class T2>
class numChar
{
protected:
public:
    T1 data1;
    T2 data2;
    numChar(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }
    void display()
    {
        cout << this->data1 << this->data2 << endl;
    }
};

int main()
{
    numChar<int, int> n(3, 3);
}