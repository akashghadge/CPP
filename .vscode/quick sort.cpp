#include <iostream>
using namespace std;
int loc;
static int a;
void quick_sort(int *, int, int);
void swap_element(int *, int *);
int main()
{
    int size;
    cin >> size;
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEASE ENTER THE NO IN THE ARRAY AT THE POSITION " << i << " :" << endl;
        cin >> arr[i];
    }
    quick_sort(arr, 0, size);
    for (i = 0; i < size; i++)
    {
        cout << "THE NO IN THE ARRAY AT THE POSITION " << i << " IS THE : " << arr[i] << endl;
    }
    cout << "THE VALUE OF THE STATIC INT IS THE :" << a << endl;
}
// partion array will make the only one swaping element at the time
int partion_array(int *arr, int lb, int ub)
{
    a++;
    int pivot;
    pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {

        while (pivot >= arr[start])
        {
            start++;
        }
        while (pivot < arr[end])
        {
            end--;
        }
        if (start < end)
        {
            swap_element(&arr[start], &arr[end]);
        }
    }
    swap_element(&arr[lb], &arr[end]);
    return end;
}
void quick_sort(int *arr, int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partion_array(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
void swap_element(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}