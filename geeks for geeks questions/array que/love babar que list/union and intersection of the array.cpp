#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr1[size];
        int arr2[size];
        int arr_intersection[size];
        int arr_union[size + size];
        int arr_union_i = 0;
        int arr_intersection_i = 0;
        int i;
        cout << "FOR FIRST ARRAY:" << endl;
        for (i = 0; i < size; i++)
        {
            cin >> arr1[i];
        }
        cout << "FOR SECOND ARRAY:" << endl;
        for (i = 0; i < size; i++)
        {
            cin >> arr2[i];
        }
        int j;
        j = 0;
        int turn = 0;
        for (i = 0; i < size; i++)
        {
            turn = 0;
            // arr_union[arr_union_i] = arr1[j];
            for (j = 0; j < size; j++)
            {
                if (arr1[i] == arr2[j] && turn == 0)
                {
                    arr_intersection[arr_intersection_i] = arr1[i];
                    arr_intersection_i++;
                    turn = 1;
                }
            }
        }

        for (i = 0; i < arr_intersection_i; i++)
        {
            cout << arr_intersection[i] << endl;
        }
    }
}