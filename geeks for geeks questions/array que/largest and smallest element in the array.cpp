#include <iostream>
using namespace std;
void isSmallLarge(int *array, int size);
int main()
{
    int size = 10;
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "PLEAASE ENTER THE NO AT THE " << i << " INDEX" << endl;
        cin >> arr[i];
    }
    isSmallLarge(arr, size);
}
void isSmallLarge(int *array, int size)
{
    int count_small = 0;
    int count_large = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if (array[i] >= array[j])
            {
                count_large++;
            }
            if (array[i] <= array[j])
            {
                count_small++;
            }
        }
        if (count_large == size)
        {
            cout << "THE " << array[i] << " PRESENT AT THE " << i << " INDEX IS THE LARGEST NO " << endl;
        }
        if (count_small == size)
        {
            cout << "THE " << array[i] << " PRESENT AT THE " << i << " INDEX IS THE SMALLEST NO " << endl;
        }
        count_small = 0;
        count_large = 0;
    }
}