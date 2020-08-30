#include <iostream>
using namespace std;
class BASE
{
public:
    int a = 1;
    virtual void display() = 0;
};
class DER1 : public BASE
{
public:
    int a = 2;
    void display()
    {
        cout << "THE DISPLAY FUNCTION OF THE DER 1:" << a << endl;
    }
};
class DER2 : public BASE
{

public:
    int a = 3;
    void display()
    {
        cout << "THE DISPLAY FUNCTION OF THE DER 2:" << a << endl;
    }
};
int main()
{
    DER1 *d11;
    DER1 obj_der1_1;
    d11 = &obj_der1_1;
    DER2 *d12;
    DER2 obj_der2_1;
    d12 = &obj_der2_1;
    d11->display();
    d12->display();
}
//HERE if you declared virtual function_name(){}=0;
// then you must make the function_name() function in evry derived class