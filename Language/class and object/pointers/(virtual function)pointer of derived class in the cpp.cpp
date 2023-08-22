#include <iostream>
using namespace std;
class BASE
{
public:
    int a = 2;
    virtual void display()
    {
        cout << "THE VALUE OF THE A IS THE :" << a << endl;
    }
};
class DER : public BASE
{
public:
    int a_der = 3;
    void display()
    {
        cout << "THE VALUE OF THE A DER IS THE :" << a_der << endl;
    }
};
int main()
{
    BASE *b1;
    BASE obj_base;
    DER *d1;
    DER obj_der;
    b1 = &obj_der;
    b1->display();
}
//it will run the base class display() and
//  if you want to run display() of der you should make the base display() virtual
// if display of the der is not present base display would be run.