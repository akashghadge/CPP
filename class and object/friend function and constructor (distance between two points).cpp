#include <iostream>
#include <math.h>
using namespace std;
class DISTANCE1;
class DISTANCE2;
class DISTANCE1
{
    int a, b;

public:
    DISTANCE1(int x, int y)
    {
        a = x;
        b = y;
    }
    friend void calculation(DISTANCE1 o1, DISTANCE2 o2);
};
class DISTANCE2
{
    int c, d;
public:
    DISTANCE2(int x, int y)
    {
        c = x;
        d = y;
    }

    friend void calculation(DISTANCE1 o1, DISTANCE2 o2);
};

int main()
{
    DISTANCE1 D1(1, 0);
    DISTANCE2 D2(4, 0);
    calculation(D1, D2);
}
void calculation(DISTANCE1 o1, DISTANCE2 o2)
{
    float data;
    data = sqrt(pow(o1.a - o2.c, 2) + pow(o1.b - o2.d, 2));
    cout << "THE DISTANCE BETWEEN THE TWO POINTS ARE THE " << data;
}