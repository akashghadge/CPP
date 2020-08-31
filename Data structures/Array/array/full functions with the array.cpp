#include <iostream>
using namespace std;
int *creat(int);
void display(int *, int);
void reverse(int *, int);
void reverse_1(int *, int);
void delete_element(int *, int, int);
int main()
{
    int size;
    cout << "PLEASE ENTER HOW MUCH SIZE OF THE ARRAY YOU REQUIRED:" << endl;
    cin >> size;
    int *base = (creat(size));
    cout << (base) << endl;
    display(base, size);
    reverse_1(base, size);
    cout << "AFTER REVERSING THE ARRAY" << endl;
    display(base, size);
    delete_element(base, size, 1);
    display(base, size);
}
int *creat(int size)
{
    int i;
    int *ptr = new int[size];
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE NO AT THE " << i << "POSITINS:" << endl;
        cin >> ptr[i];
        // cout << "YOU ENTER THE " << array[i] << "AT THE " << i << "POSITION" << endl;
    }
    cout << ptr << endl;
    return ptr;
}
void display(int *base, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "THE ARRAY HAVE THE " << *(base + i)
             << "NUMBER AT THE " << i
             << "POSITION" << endl;
    }
}
void reverse(int *base, int size)
{
    int i;
    int j = 0;
    int temp[size];
    cout << "WE ARE REVERSING YOUR ARRAY.." << endl;

    for (i = size - 1; i >= 0; i--)
    {
        temp[i] = base[j];
        j++;
    }
    j = 0;
    for (i = 0; i < size; i++)
    {
        base[j] = temp[i];
        j++;
    }
}
void reverse_1(int *base, int size)
{
    int mid = (size - 1) / 2;
    int i = 0;
    int end = size;
    for (i = 0; i <= mid; i++)
    {
        end--;
        swap(base[i], base[end]);
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void delete_element(int *base, int size, int index)
{
    if (index >= size)
    {
        cout << "PLEASE ENTER THE CORRECT INDEX:)" << endl;
    }
    else if (index == size - 1)
    {
        delete &base[index];
    }
    else
    {
        int i;
        int index_next;
        index_next = index + 1;
        for (i = index; i < size; i++)
        {
            swap(base[i], base[index_next]);
            index_next++;
        }
        delete &base[i];
    }
}
