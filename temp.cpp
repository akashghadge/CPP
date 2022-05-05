#include <stdio.h>
float add(int, int);
int main()
{
    int num[4] = {1, 3, 4, 5};
    int *ptr = num;
    ptr++;
    printf("%d", *ptr);
}