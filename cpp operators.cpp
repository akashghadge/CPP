#include <iostream>
// justification library for the cpp
#include <iomanip>

#include "operations.h"
#define EVEN 1;
using namespace std;
int a = 3;
int b = 2;
int main()
{
    // ARETHMATIC OPERATORS IN CPP
    cout << "THE ADDITION IS :" << a + b << endl;
    cout << "THE SUBSTRACTION IS :" << a - b << endl;
    cout << "THE MULTIPICATION IS :" << a * b << endl;
    cout << "THE DIVISION IS :" << a / b << endl
         << endl;
    // with justification ARETHMATIC OPERATORS IN CPP

    cout << "THE MODULAS IS :" << setw(4) << a % b << endl;
    cout << "THE ADDITION IS :" << setw(4) << a + b << endl;
    cout << "THE SUBSTRACTION IS :" << setw(4) << a - b << endl;
    cout << "THE MULTIPICATION IS :" << setw(4) << a * b << endl;
    cout << "THE DIVISION IS :" << setw(4) << a / b << endl;
    cout << "THE MODULAS IS :" << setw(4) << a % b << endl;
    int data = power(10, 5);
    cout << "THE POWER IS THE : " << data << endl;
    bool is_prime = isprime(7);
    // printf("the no is %d\n",is_prime);
    if (is_prime == 1)
    {
        printf("prime\n");
    }
    else
    {
        printf("not prime\n");
    }
    bool is_evenodd = isevenodd(4);
    printf("the evenodd :%d", is_evenodd);
}
