#include <iostream>
using namespace std;
// #include "C:\Users\ASUS\Desktop\C++\header files in cpp\headerfile.h"
int digits(int, int *);
int prime_made(int);
int check(int);
int main()
{
    int target;
    cout << "PLEASE ENTER THE TARGET NO" << endl;
    cin >> target;
    int result;
    result = prime_made(target);
    cout << "THE RESULT IS  " << result << endl;
}
int prime_made(int target)
{
    int i;
    int *arr = new int[10];
    int size;
    int j;
    int temp;
    int count = 0;
    int count_main = 0;
    for (i = 2; i < 1000000; i++)
    {
        size = digits(i, arr);
        // cout << "THE SIZE IS THE " << size << endl;
        count = 0;

        for (j = 0; j < size; j++)
        {
            temp = check(arr[j]);
            // cout << "THE VALUE OF THE TEMP IS THE :" << temp << " NUM IS :" << i << endl;
            if (temp == 1)
            {
                count++;
                temp = 0;
            }
        }
        if (count == size)
        {
            count_main++;
        }
        if (count_main == target)
        {
            return i;
            break;
        }
    }
}
int check(int t)
{
    if (t == 1)
    {
        return 0;
    }

    else if (t == 2)
    {
        return 1;
    }
    else if (t == 3)
    {
        return 1;
    }
    else if (t == 5)
    {
        return 1;
    }
    else if (t == 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int digits(int num, int *digit)
{
    int i = 0;
    while (num)
    {
        digit[i] = num % 10;
        num = num / 10;
        i++;
    }
    return i;
}