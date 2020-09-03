#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int precedence(char);
int associativity(int);
void precedence_check(char, int, int);
STACK_CHAR stk;
string infix;

int main()
{
    char peek_temp;
    stk.creat_stack(50);
    cout << "PLEASE ENTER THE INFIX EXPRESION :" << endl;
    cin >> infix;
    int length = infix.length();
    // cout << "THE LENGTH OF THE STRING IS THE :" << length << endl;
    int i = 0;
    int pre = 0;
    int asso = 0;
    while (i < length)
    {
        pre = precedence(infix[i]);
        asso = associativity(pre);
        precedence_check(infix[i], pre, asso);
        i++;
    }
    peek_temp = stk.peek_stack();
    stk.pop_stack_all();
    // cout << "THE ARRAY HAVE THE PEEK TEMP VALUE IS :" << peek_temp << endl;

    // cout << "hi : " << peek_temp << endl;
}
int associativity(int pre)
{
    if (pre % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char p)
{
    if (p == '(' || p == ')')
    {
        return 5;
    }
    else if (p == 'S')
    {
        return -20;
    }

    else if (p == '^')
    {
        return 4;
    }
    else if (p == '*' || p == '/')
    {
        return 3;
    }
    else if (p == '+' || p == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void precedence_check(char a, int pre, int asso)
{
    int temp_pre;
    char peek;
    // int terminate = 1;
    while (true)
    {
        peek = stk.peek_stack();
        temp_pre = precedence(peek);
        if (pre == -1)
        {
            cout << a;
            break;
        }
        else if (pre > temp_pre)
        {
            stk.push_stack(a);
            break;
        }
        else if (pre == temp_pre)
        {
            if (asso == 0)
            {
                stk.pop_stack();
                // stk.push_stack(a);
                // break;
            }
            else
            {
                stk.push_stack(a);
                break;
            }
        }
        else if (pre < temp_pre)
        {
            stk.pop_stack();
        }
    }
}