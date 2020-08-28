#include <iostream>
using namespace std;
class BASE1
{
public:
    void printHello()
    {
        cout << "HELLO" << endl;
    }
};
class BASE2
{
public:
    void printHello()
    {
        cout << "HELLO WORLD" << endl;
    }
};
class DER : public BASE1, public BASE2
{
public:
    // printHello();         IT SHOWS THE AMBIGOUS PROBLEM CAUSE WE DID NOT DECLARE HERE WHICH printHello(); USE.
    void printHello()
    {
        BASE2 ::printHello();
    }
};

int main()
{
    DER d;
    d.printHello();
}