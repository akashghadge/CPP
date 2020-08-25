#include <iostream>
#include <string.h>
using namespace std;

class first_class
{
private:
    int b = 1;

public:
    int a = 2;
    void get();
    void display()
    {
        cout << "b HAVE THE VALUE OF THE " << b << endl;
        cout << "a HAVE THE VALUE OF THE " << a << endl;
    }
};
void first_class ::get()
{
    cout << "PLEASE ENETER THE VAVLUE OF THE a :" << endl;
    cin >> a;
    cout << "PLEASE ENTER THE VALUE OF THE b:" << endl;
    cin >> b;
    cout << "THE VALUE OF THE a IS  " << a << "THE VALUE OF THE b IS THE " << b << endl;
}
class emptyclass
{
};

main()
{
    first_class person;
    // cout << "THE VALUE OF THE a IS THE " << person.a << endl;
    // person.get();
    // person.display();
    // first_class person1;
    // person1.get();
    // person1.display();

    // person.display();
    // cout << "THE SIZE OF THE CLASS IS THE : " << sizeof(emptyclass) << endl;
}