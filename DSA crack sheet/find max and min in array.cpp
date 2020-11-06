#include <iostream>
using namespace std;
void maxNumber(int *, int);
void minNumber(int *, int);
void swapNumber(int *, int *);
void printArray(int *, int);
int main()
{
    int size = 6;
    int a[size] = {10, 20, 30, 40, 50, 60};
    minNumber(a, size);
    maxNumber(a, size);
}

void maxNumber(int *a, int size)
{
    int i;
    int min = 0;
    for (i = 0; i < size; i++)
    {
        if (a[min] < a[i])
        {
            min = i;
        }
    }
    cout << "THE MIN NUMBER IS THE :" << a[min] << endl;
}
void minNumber(int *a, int size)
{
    int i;
    int max = 0;
    for (i = 0; i < size; i++)
    {
        if (a[max] > a[i])
        {
            max = i;
        }
    }
    cout << "THE MAX NUMBER IS THE :" << a[max] << endl;
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