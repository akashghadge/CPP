#include <iostream>
using namespace std;
class BASE1
{
protected:
    int data = 10;

public:
    void printHello()
    {
        cout << "HELLO" << endl;
    }
};
class BASE2 : public virtual BASE1
{
public:
    void printHello()
    {
        cout << "HELLO WORLD" << endl;
    }
};
class BASE3 : public virtual BASE1
{
public:
    void printHello()
    {
        cout << "HELLO WORLD" << endl;
    }
};
class DER : public BASE3, public BASE2
{
public:
    void getData()
    {
        cout << "THE DATA IS THE :" << data << endl;
    }
};

int main()
{
    DER d;
    d.getData();
}