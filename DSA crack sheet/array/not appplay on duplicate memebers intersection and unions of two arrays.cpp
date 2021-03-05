#include <iostream>
using namespace std;
#include <stdlib.h>

void printArray(int *a, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
}
void swap_element(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int size1;
    int size2;

    int t;
    cin >> t;
    while (t--)
    {
        cin >> size1;
        cin >> size2;
        int arr1[size1];
        int arr2[size2];
        int interSize;
        if (size1 > size2)
        {
            interSize = size1;
        }
        else
        {
            interSize = size2;
        }
        int arr_inter[interSize];
        int arr_union[size1 + size2];
        int index_inter = 0;
        int index_union = 0;
        int i;
        cout << "ELEMENT OF THE FIRST ARRAY" << endl;

        for (i = 0; i < size1; i++)
        {
            cin >> arr1[i];
        }
        cout << "ELEMENT OF THE SECOND ARRAY" << endl;
        for (i = 0; i < size2; i++)
        {
            cin >> arr2[i];
        }
        for (i = 0; i < size1; i++)
        {
            int element = arr1[i];
            arr_union[index_union++] = element;
            int j;
            for (j = 0; j < size2; j++)
            {
                if (i == size1 - 1)
                {
                    arr_union[index_union++] = arr2[j];
                }
                if (element == arr2[j])
                {
                    arr_inter[index_inter++] = element;
                }
            }
        }
        cout << "Intersection" << endl;
        printArray(arr_inter, index_inter);
        cout << "Union" << endl;
        printArray(arr_union, index_union);
    }
}
