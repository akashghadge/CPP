#include <iostream>
using namespace std;
#include "headerfile.h"
int main()
{
    int num = 21;
    int *digitst = new int[10];
    int size;
    size = digits(num, digitst);
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "THE DIGIT AT THE POSITION " << i << " IS " << *(digitst + i) << endl;
    }
}