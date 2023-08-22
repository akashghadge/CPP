#include <iostream>
using namespace std;
class BASE1
{
protected:
    int data_base1;

public:
    BASE1() {}
    BASE1(int a) : data_base1(a)
    {
    }
};
class BASE2
{
protected:
    int data_base2;

public:
    BASE2() {}
    BASE2(int a) : data_base2(a)
    {
    }
};

class DER : public BASE1, public BASE2
{
    int data_der1;
    int data_der2;

public:
    DER(int a, int b, int c, int d) : data_der2(d), data_der1(c), BASE1(a), BASE2(b)
    {
        cout << "THE VALUE OF THE BASE 1 IS : " << data_base1 << endl;
        cout << "THE VALUE OF THE BASE 2 IS : " << data_base2 << endl;
        cout << "THE VALUE OF THE DER FOR 1:" << data_der1 << endl;
        cout << "THE VALUE OF THE DER FOR 2:" << data_der2 << endl;
    }
};

int main()
{
    DER obj(1, 2, 3, 4);
}