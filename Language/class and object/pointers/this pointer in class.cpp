#include <iostream>
using namespace std;
class A
{
public:
    int a;
    void setData(int a)
    {
        cout << "STARTING YOUR PROGRAM" << endl;

        this->a = a;
        cout << "YOU SET THE VALUE OF THE VARIALBLE:" << a << endl;
    }
    void getData()
    {
        cout << "THE VALUE OF THE VARIALBLE:" << a << endl;
    }
};
int main()
{
    // cout << "STARTING YOUR PROGRAM" << endl;
    // A a1;
    // a1.setData(2);
    // a1.getData();
    // A *d1 = new (A);
    // (*d1).setData(1); //here () requires cause . have the higher precedence
    // (*d1).getData();

    A *a1;
    A obj;
    a1 = &obj;
    a1->setData(2);
    a1->getData();
    obj.getData();
}