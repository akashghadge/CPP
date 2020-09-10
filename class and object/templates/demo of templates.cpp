#include <iostream>
using namespace std;
template <class T>
class Emp
{
public:
    T a;
    Emp() {}
    Emp(T a) { this->a = a; }
    void setData(T a)
    {
        this->a = a;
    }
    void getData()
    {
        cout << a;
    }
};
int main()
{
    Emp<int> e1(10);
    e1.getData();
}