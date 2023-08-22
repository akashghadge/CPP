#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int main()
{
    Array<int> a1(10);
    a1.create_array();
    a1.display_array();
    a1.delete_element(5);
    a1.display_array();
    a1.append_array(5);
    a1.display_array_full();
}