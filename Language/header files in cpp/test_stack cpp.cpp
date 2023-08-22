#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int main()
{
    STACK s1;
    s1.creat_stack(5);
    s1.display_array();
    cout << "AFTER CREATING STACK" << endl;
    s1.push_stack(2);
    s1.display_array();
    cout << "AFTER PUSH STACK" << endl;
    s1.pop_stack();
    s1.display_array();
    cout << "AFTER POPING STACK" << endl;
    s1.peek_stack();
}