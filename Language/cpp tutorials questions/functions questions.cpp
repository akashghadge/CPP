#include <iostream>
using namespace std;
int factorial(int fact);
int power(int, int);
void rom_converter(int);
int prime_factors(int);
int is_leap();
float multiple(int, float);
int main()
{
    //     int fact;
    //     int result;
    //     cout << "PLEASE ENTER THE NUMBER WOULD YOU LIKE TO FIND THE FACTORIAL" << endl;
    //     cin >> fact;
    //     cout << "YOU ENTERD THE " << fact << endl;
    //     if (fact >= 1)
    //     {
    //         result = factorial(fact);
    //     }
    //     else
    //     {
    //         cout << "PLEASE ENTER THE POSITIVE NO AND NOT ZERO OR NEGATIVE ........." << endl;
    //     }

    //     cout << "THE RESULT IS THE :" << result << endl;

    //     int expo;
    // int base;
    // int result_power;
    // cout << "PLEASE ENTER THE BASE NUMBER AND THE EXPO.." << endl;
    // cin >> base;
    // cin >> expo;
    // result_power = power(base, expo);
    // cout << "THE RESULT IS " << result_power << endl;

    // int initial_no_romconverter;
    //  cout << "PLEASE ENTER THE NO WHICH WOULD YOU LIKE TO CONVERT IN TO ROMAN NO:" << endl;
    // cin >> initial_no_romconverter;
    // rom_converter(initial_no_romconverter);

    //    int num;
    //         cout << "ENTER THE NUMBER" << endl;
    //         cin >> num;
    //         prime_factors(num);

    int a;
    while (a)
    {
        int num1;
        float num2;
        cout << "ENTER THE NUMBER1" << endl;
        cin >> num1;
        cout << "ENTER THE NUMBER2" << endl;
        cin >> num2;
        float sum;
        sum = multiple(num1, num2);
        cout << "THE MULTIPLE IS THE " << sum << endl;

        cout << "ENETER A" << endl;
        cin >> a;
    }
}
int factorial(int fact)
{
    int i = 1;
    int result = 1;

    for (i = 1; i <= fact; i++)
    {
        result = result * i;
    }
    return result;
}
int power(int base, int expo)
{
    int i = 1;
    int result = 1;
    for (i = 1; i <= expo; i++)
    {
        result = result * base;
    }
    return result;
}
void rom_converter(int initial_no)
{
    int i;
    static int j = 0;
    int temp;
    char result[50];
    int init;
    for (init = 0; init < 50; init++)
    {
        result[init] = EOF;
    }

    temp = initial_no / 1000;
    for (i = 1; i <= temp; i++)
    {
        result[j] = 'm';
        j++;
    }
    initial_no = initial_no % 1000;
    temp = initial_no / 500;
    if (temp)
    {
        result[j] = 'd';
        j++;
    }
    initial_no = initial_no % 500;
    temp = initial_no / 100;
    for (i = 1; i <= temp; i++)
    {
        result[j] = 'c';
        j++;
    }
    initial_no = initial_no % 100;
    temp = initial_no / 50;
    if (temp)
    {
        result[j] = 'l';
        j++;
    }
    initial_no = initial_no % 50;
    temp = initial_no / 10;
    for (i = 1; i <= temp; i++)
    {
        result[j] = 'x';
        j++;
    }
    initial_no = initial_no % 10;
    switch (initial_no)
    {
    case 1:
        result[j] = 'i';
        j++;
        break;

    case 2:
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        break;

    case 3:
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        break;

    case 4:
        result[j] = 'i';
        j++;
        result[j] = 'v';
        j++;
        break;

    case 5:
        result[j] = 'v';
        j++;
        break;

    case 6:
        result[j] = 'v';
        j++;
        result[j] = 'i';
        j++;
        break;

    case 7:
        result[j] = 'v';
        j++;
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        break;

    case 8:
        result[j] = 'v';
        j++;
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        result[j] = 'i';
        j++;
        break;

    case 9:
        result[j] = 'i';
        j++;
        result[j] = 'x';
        j++;
        break;

    default:
        break;
    }
    j = 0;
    while (result[j] != EOF)
    {
        cout << result[j] << "\t";
        j++;
    }
    cout << endl;
    j = 0;
}
int is_leap()
{
    int leap;
    cout << "PLEASE ENTER THE YEAR WOULD YOU LIKE TO CHECK:" << endl;
    cin >> leap;
    if (leap % 4 == 0)
    {
        cout << "THE " << leap << " IS LEAP YEAR" << endl;
    }
    else
    {
        cout << "THE " << leap << " IS NOT LEAP YEAR" << endl;
    }
}
int prime_factors(int num)
{
    int i;
    int temp_num;
    temp_num = num;
    for (i = 2; i < temp_num;)
    {
        if (num % i == 0)
        {
            cout << i << endl;
            num = num / i;
        }
        else
        {
            i++;
        }
    }
}
float multiple(int num1, float num2)
{
    float sum;
    sum = (float)(num1 * num2);
    return sum;
}