#include <iostream>
using namespace std;
int calculation(struct Height arr[], int size);
struct Height
{
    int feet;
    int inche;
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        int size;
        cin >> size;
        Height arr[size];
        for (i = 0; i < size; i++)
        {
            cin >> arr[i].feet;
            cin >> arr[i].inche;
        }
        for (i = 0; i < size; i++)
        {
            cout << "IN FOOT : " << endl;
            cout << arr[i].feet << endl;
            cout << "IN INCHES :" << endl;
            cout << arr[i].inche << endl;
        }
        int index = calculation(arr, size);
        cout << "AT THE " << index << " HAVE THE HIGHEST HEIGHT" << endl;
    }
}
int calculation(struct Height arr[], int size)
{
    int i;
    int test_arr[size];
    for (i = 0; i < size; i++)
    {
        test_arr[i] = (arr[i].feet * 12) + arr[i].inche;
    }
    int j = 0;
    for (i = 0; i < size; i++)
    {
        if (test_arr[j] < test_arr[i])
        {
            j = i;
        }
    }
    return j;
}