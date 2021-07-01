#include <stdio.h>
#include <stdlib.h>>
void fun() { printf("I am from fun"); }
void dun() { printf("I am from dun"); }
void main()
{
    int xxx[10] = {5};
    printf("%d %d", xxx[1], xxx[9]);
}
