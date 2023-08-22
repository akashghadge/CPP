#include <iostream>
using namespace std;
class static_demo
{
public:
    static int a;
    void getCount()
    {
        cout << "THE VALUE OF THE COUNTER IS THE " << a << endl;
        a++;
    }
    static void getinfo()
    {
        cout << "THE VALUE OF THE " << a << endl;
        a++;
    }
};
int static_demo ::a;
int main()
{
    static_demo s, p, q;
    s.getCount();
    p.getCount();
    q.getCount();
    static_demo ::getinfo();
    static_demo ::getinfo();
    q.getinfo();
    p.getinfo();
}