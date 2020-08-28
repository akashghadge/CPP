#include <iostream>
using namespace std;
class BASE1
{
    int data_base1;

public:
    BASE1()
    {
        cout << "THE BASE1 CONSTRUCTOR IS INVOKES..." << endl;
    }
};
class BASE2
{
    int data_base2;

public:
    BASE2()
    {
        cout << "THE BASE2 CONSTRUCTOR IS INVOKES..." << endl;
    }
};
// class DER : public BASE1, public BASE2 //WHICH IS DECLARED FIRST IT WILL INVOKES FIRST..
// {                                            //AFTER DER CONTRUCTOR IS INVOKES
//     int data_der;

// public:
//     DER()
//     {
//         cout << "THE DER CONSTRUCTOR IS INVOKES..." << endl;
//     }
// };

class DER : public virtual BASE1, virtual public BASE2 //VIRTUAL CONTRUCTOR IS INVOKES FIRST IT HAVE HIGHER PRCEDANCE..
{                                                      //AFTER DER CONTRUCTOR IS INVOKES
    int data_der;

public:
    DER()
    {
        cout << "THE DER CONSTRUCTOR IS INVOKES..." << endl;
    }
};

int main()
{
    DER d;
}