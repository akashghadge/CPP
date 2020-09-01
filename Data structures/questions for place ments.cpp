#include <iostream>
#include <string.h>
using namespace std;
void swap(int *, int *);
void swap_string(string *, string *);
void display(struct EXAM *, int size);
void string_sorting(struct EXAM *, int size);
// #include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
struct EXAM
{
    string name;
    int marks;
};
int main()
{
    int size = 5;
    // string a = "akash";
    // string b = "ghadge";
    // cout << "THE A STRING IS " << a << endl;
    // cout << "THE B STRING IS " << b << endl;

    // swap_string(&a, &b);
    // cout << "THE A STRING IS " << a << endl;
    // cout << "THE B STRING IS " << b << endl;
    int i;
    EXAM e[size];
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE NAME OF THE STUDENT:" << endl;
        cin >> e[i].name;
        cout << "PLEASE ENTER THE MARKS :" << endl;
        cin >> e[i].marks;
    }
    string_sorting(&e[0], size);
    display(&e[0], size);
}
void string_sorting(struct EXAM *e, int size)
{

    int i;
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if (e[i].name == e[j].name)
            {
                if (e[i].marks > e[j].marks)
                {
                    swap(&e[i].marks, &e[j].marks);
                }
            }
            else if (e[i].name < e[j].name)
            {
                swap_string(&e[i].name, &e[j].name);
                swap(&e[i].marks, &e[j].marks);
            }
        }
    }
}
void display(struct EXAM *e, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "THE NAME OF THE " << e[i].name << endl;
        cout << "THE MARKS OF THE " << e[i].marks << endl;
    }
}
void swap_string(string *a, string *b)
{
    string temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}