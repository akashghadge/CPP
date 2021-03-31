#include <iostream>
using namespace std;
#include "vector"
int main()
{
    int a = 10;
    // getting the number converted into binary number
    vector<int> vec;
    while (a != 0)
    {
        vec.push_back(a % 2);
        a = a >> 1;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d\n", vec[i]);
    }

    // getting odd-even of number using bit
    int mask = 1;
    int oddEven = 20;
    if (oddEven & mask)
    {
        printf("Number is Odd\n");
    }
    else
    {
        printf("Number is Even\n");
    }

    // masking of bit
    mask = 1;
    mask = mask << 2;
    printf("%d\n", mask);

    // getting bit value
    int set = 10;
    mask = 1;
    mask = mask << 2;
    // if ans is zero then bit is zero and for non zero ans bit is 1
    printf("%d\n", mask & set);

    // changing only one bit to 1
    set = 10;
    set = set | mask;
    printf("%d\n", set);

    // seting bit to zero
    mask = 1;
    mask = mask << 3;
    set = 15;
    set = set & ~(mask);
    printf("%d\n", set);

    // counting number of 1 bits in number
    set = 10;
    int count = 0;
    while (set)
    {
        set = set & (set - 1);
        count++;
    }
    printf("No of Bits : %d\n", count);

    int aNum = 10;
    int bNum = 5;
    int result = aNum ^ bNum;
    count = 0;
    while (result)
    {
        result = result & (result - 1);
        count++;
    }
    printf("No of Bits Need to change :%d\n", count);
}