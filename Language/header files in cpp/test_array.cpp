#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int main()
{
    ARRAY a1(5);
    a1.create_array();
    // a1.display_array();
    // a1.reverse_array();
    // a1.display_array();
    // a1.delete_element(2);
    // a1.display_array();
    a1.arr[4] = 100;
    a1.display_array();
    a1.display_array_one(4);
}