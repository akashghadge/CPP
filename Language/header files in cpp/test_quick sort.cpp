#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int main()
{
    int size;
    size = 5;
    ARRAY a1;
    a1.create_array();
    quick_sort(a1.arr, 0, size);
    // bublesort(a1.arr, size);
    a1.display_array();
}