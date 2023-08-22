#include <iostream>
using namespace std;
#include "stack_array.h"
#include "test.h"
int main()
{
    int top = -1;
    int size = 10;
    int *stack1 = creat_stack(size);
    top = push(stack1, size, top, 10);
    top = push(stack1, size, top, 20);
    display(stack1, size, top);
    top = pop(stack1, size, top);
    display(stack1, size, top);

    cout << "THE SECOND STACK DATA IS HERE" << endl;
    int top1 = -1;
    int size1 = 10;
    int *stack2 = creat_stack(size1);
    top1 = push(stack2, size1, top1, 30);
    top1 = push(stack2, size1, top1, 40);
    display(stack2, size1, top1);
    top1 = pop(stack2, size1, top1);
    display(stack2, size1, top1);

    A a1(10);
    a1.display();
}