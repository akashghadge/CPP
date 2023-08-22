#include <iostream>
using namespace std;
#include "headerfile.h"
int main()
{
    ARRAY a1;
    a1.create_array();
    bool result;
    result = linear_serch(a1.arr, a1.size, 10);
    cout << "THE FINAL RESULT IS THE : " << result << endl;
}