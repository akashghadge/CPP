#include <iostream>
using namespace std;
class DEMO
{
    int i;
    float j;

public:
    DEMO() {}
    DEMO(int a, float b) : i(a), j(b) {}
    void setData(int a, float b)
    {
        i = a;
        j = b;
    }
    void getData()
    {
        cout << "THE VALUE AT THE I :" << i << endl;
        cout << "THE VALUE AT THE J:" << j << endl;
    }
};
int main()
{ //normal init of the object.
    // DEMO d1(1, 2.2);
    // d1.getData();

    //using the new and delete keywords (mantose jindgi)

    DEMO *d1 = new (DEMO);
    (*d1).setData(1, 2.2); //here () requires cause . have the higher precedence
    (*d1).getData();

    // using arrow operator
    // d1->setData(1, 2.2);
    // d1->getData();
}