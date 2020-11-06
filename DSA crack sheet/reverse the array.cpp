#include <iostream>
using namespace std;
void reverseArray(int *, int);
void swapNumber(int *, int *);
void printArray(int *, int);
int main()
{
    int size = 6;
    int a[size] = {10, 20, 30, 40, 50, 60};
    printArray(a, size);
    reverseArray(a, size);
    printArray(a, size);
}

void reverseArray(int *a, int size)
{
    int i;
    int j = size - 1;
    for (i = 0; i < (size / 2); i++)
    {
        swapNumber(&a[i], &a[j - i]);
    }
}

void swapNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}