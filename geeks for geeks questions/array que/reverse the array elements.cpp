#include <iostream>
using namespace std;
void reverse_array(int *, int);
int main()
{
    int size = 7;
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEAASE ENTER THE NO AT THE " << i << " INDEX" << endl;
        cin >> arr[i];
    }
    for (i = 0; i < size; i++)
    {
        cout << "THE NO AT THE " << i << " IS THE " << arr[i] << endl;
    }
    reverse_array(arr, size);
    for (i = 0; i < size; i++)
    {
        cout << "THE NO AT THE " << i << " IS THE " << arr[i] << endl;
    }
}
void reverse_array(int *arr, int size)
{
    int middle = size / 2;
    int i;
    int j;
    j = size - 1;
    for (i = 0; i < middle; i++)
    {
        swap(arr[i], arr[j]);
        j--;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}