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
        int array[size];
        int i;
        for (i = 0; i < size; i++)
        {
            cin >> array[i];
            cout << endl;
        }
        int j = 0;
        for (i = 0; i < size; i++) //asuming the at first place positive no are their
        {
            if (i % 2 == 0 && array[i] < 0) //at first place if we not found and positive we replace with it with next positive no
            {
                for (j = i + 1; j < size; j++)
                {
                    if (array[j] > 0)
                    {
                        swap(array[i], array[j]);
                        break;
                    }
                }
            }
            if (i % 2 == 1 && array[i] > 0) //same as first if condition but for negetive no //
            {
                for (j = i + 1; j < size; j++)
                {
                    if (array[j] < 0)
                    {
                        swap(array[i], array[j]);
                        break;
                    }
                }
            }
        }
        cout << "THE RESULT IS THE :" << endl;
        for (i = 0; i < size; i++)
        {
            cout << array[i] << endl;
        }
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}