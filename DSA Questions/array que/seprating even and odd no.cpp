#include <iostream>
using namespace std;
void create(int *, int);
void display(int *, int);
void seprate(int *, int);
int main()
{
    int size = 10;
    int arr[size];
    create(arr, size);
    display(arr, size);
    seprate(arr, size);
    display(arr, size);
}
void create(int *arr, int size)
{
    int i = 1;
    for (i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}
void display(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void seprate(int *arr, int size)
{
    int temp[size];
    int i;
    int start = 0;
    int end = size - 1;
    for (i = 0; i < size; i++)
    {
        if (start > end)
        {
            break;
        }

        if (arr[i] % 2 == 0)
        {
            temp[start] = arr[i];
            start++;
        }
        else
        {
            temp[end] = arr[i];
            end--;
        }
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}