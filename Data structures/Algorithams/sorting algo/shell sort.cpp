#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
void shell_sort(int *, int);
int main()
{
    ARRAY a1(5);
    a1.create_array();
    a1.display_array();
    shell_sort(a1.arr, a1.size);
    a1.display_array();
}
void shell_sort(int *arr, int size)
{
    int gap = size / 2;
    int j;
    int i;
    for (gap; gap >= 1;)
    {
        cout << "HO" << gap << endl;

        for (j = gap; j < size; j++)
        {
            for (i = j - gap; i >= 0;)
            {
                if (arr[i + gap] > arr[i])
                {
                    break;
                }
                else
                {
                    swap(arr[i + gap], arr[i]);
                }
                i = i - gap;
            }
        }
        gap = gap / 2;
    }
}