#include <iostream>
using namespace std;
class COPY_CLASS
{
public:
    int a;
    COPY_CLASS()
    {
        a = 0;
    }
    COPY_CLASS(int b)
    {
        a = b;
    }
    COPY_CLASS(COPY_CLASS &obj)
    {
        a = obj.a;
        cout << "PROGRAM CONTROLLER IN THE COPY CLASS CONTRUCTOR.." << endl;
    }
    void display()
    {
        cout << "THE VALUE OF THE A IS THE : " << a << endl;
    }
};
int main()
{
    COPY_CLASS o1;
    o1.display();

    COPY_CLASS o2(3), o3;
    o2.display();

    o3 = o2; //construct invokes but it is default contructor which is supply by the compiler
    o3.display();

    COPY_CLASS o4(o2); //copy contructor is invokes
    o4.display();
}
