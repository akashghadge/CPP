#include <iostream>
using namespace std;
int ispresent(int *, int);

int main()
{
    register int i = 0;
    cout << "PREAPARING THE PROGRAM..." << endl;
    int array[4];
    for (i = 0; i < 4; i++)
    {
        cout << "PLEASE ENTER THE NO AT THE " << i << " POSITION" << endl;
        cin >> array[i];
    }
    int check;
    cout << "PLEASE ENTER THE NO WHICH ONE WOULD YOU LIKE TO CHECK" << endl;
    cin >> check;
    int present = ispresent(array, check);
    if (present)
    {
        cout << "THE NUMBER IS PRESENT  " << present << " TIMES IN THE ARRAY" << endl;
    }
    else
    {
        cout << "THERE IS NO NUMBER PRESENT IN THE ARRAY.." << endl;
    }
}
int ispresent(int *base, int check)
{
    int i;
    int temp;
    int f = 0;
    for (i = 0; i < 4; i++)
    {
        if (check == base[i])
        {
            cout << "in the present" << endl;

            f++;
        }
    }

    return f;
}