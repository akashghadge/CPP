#include <stdio.h>
int power(int);
bool prime(int temp);
bool isevenodd(int);
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
bool isprime(int temp)
{
    int f = 1;
    int i = 2;
    for (i; i < temp; i++)
    {
        int data = temp % i;
        if (data == 0)
        {
            f = 0;
        }
    }
    if (f == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool isevenodd(int temp)
{
    if (temp % 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}