#include <iostream>
using namespace std;
int convert(int);
int power(long int, int);
int main()
{
    int num;
    cin >> num;
    int num2;
    num2 = convert(num);
    cout << num2;
}
int convert(int num)
{
    int i = 0;
    long int multi;
    int temp_num = num;
    int new_num = 0;
    int digit;
    if (num == 0)
    {
        return 5;
    }
    while (i != 3)
    {
        multi = power(10, i);
        cout << "THE MULTI IS CALLED " << multi << endl;
        digit = temp_num % (multi * 10);
        if (digit == 0)
        {
            digit = 5;
        }
        new_num = new_num + (digit * multi);
        temp_num = temp_num / (multi * 10);
        // cout << new_num << endl;
        i++;
    }
    return new_num;
}
int power(long int base, int expo)
{
    int i;
    long int temp_base;
    temp_base = base;
    if (expo == 0)
    {
        return 1;
    }
    else
    {

        for (i = 1; i <= expo; i++)
        {
            base = base * temp_base;
            if (i == 1)
            {
                base = temp_base;
            }
        }
        return base;
    }
}