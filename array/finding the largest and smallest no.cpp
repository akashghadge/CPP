#include <iostream>
using namespace std;
int islarge(int *, int);
int issmall(int * ,int);
int main()
{
    int size;
    cout << "PLEASE ENTER THE SIZE OF THE ARRAY" << endl;
    cin >> size;
    int array[size];
    register int i;
    for (i = 0; i < (size); i++)
    {
        cout << "PLEASE ENTER THE NUMBER AT POSITION " << i << endl;
        cin >> array[i];
    }
    int large = islarge(array, size);
    cout << "THE LARGEST ELEMENT IN ARRAY IS " << large << endl;
    int small = issmall(array, size);
    cout << "THE SMALLEST ELEMENT IN ARRAY IS " << small << endl;

}
int islarge(int *base, int size)
{
    register int i, j;
    int f = 0;
    for (i = 0; i < (size); i++)    
    {
        int flag = 0;
        int temp;
        temp = base[i];
        for (j = 0; j < size; j++)
        {
            if (base[i] >= base[j])
            {
                flag++;
            }
        }
        if (flag == size)
        {
            f = 1;
            break;
        }
    }
    return base[i];
}
int issmall(int *base, int size)
{
    register int i, j;
    int f = 0;
    for (i = 0; i < (size); i++)
    {
        int flag = 0;
        int temp;
        temp = base[i];
        for (j = 0; j < size; j++)
        {
            if (base[i] <= base[j])
            {
                flag++;
            }
        }
        if (flag == size)
        {
            f = 1;
            break;
        }
    }
    return base[i];
}