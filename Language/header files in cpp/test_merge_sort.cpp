#include <iostream>
using namespace std;
#include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int main()
{
    int size = 10;
    // cin >> size;
    int arr[size];
    int array[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE NO IN THE ARRAY AT THE POSITION " << i << " :" << endl;
        cin >> arr[i];
    }
    merge_sort(arr, 0, size, array);
    cout << "HELLO WORLD" << endl;
    for (i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}