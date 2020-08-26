#include <iostream>
using namespace std;
static int count;
class DESTRUCTOR_DEMO
{
public:
    int data;
    DESTRUCTOR_DEMO()
    {
        count++;
        cout << "THE CONSTRUCTOR IS CALLED ....." << count << endl;
    }
    ~DESTRUCTOR_DEMO()
    {
        count--;
        cout << "THE DESTRUCTOR IS CALLED...." << count << endl;
    }
};
int main()
{
    DESTRUCTOR_DEMO o1;
    {
        DESTRUCTOR_DEMO oo2;
    }
}