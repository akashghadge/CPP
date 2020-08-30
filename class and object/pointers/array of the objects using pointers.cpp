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
        // cout << "THE VALUE OF THE C IS THE :" << c << endl;
    }
    static void c()
    {
        static int c;
        cout << "THE VALUE OF THE C IS THE :" << c << endl;

        c++;
    }
};
int main()
{
    int i;
    int a;
    float b;
    DEMO *d1 = new (DEMO[20]);
    DEMO *ptr = d1;
    for (i = 0; i < 20; i++)
    {
        cout << "PLEASE ENTER THE 1 DATA :" << endl;
        cin >> a;
        cout << "PLEASE ENTER THE 2 DATA:" << endl;
        cin >> b;

        ptr->setData(a, b);
        ptr->getData();
        ptr->c();
        ptr++;
    }
}