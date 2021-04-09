/*
Given a number N. Find the product of the number of setbits and the number itself.


Example 1:

Input: N = 2
Output: 2
Explaination: 2 has one setbit. So, 2*1 = 2.

Example 2:

Input: N = 3
Output: 6
Explaination: 3 has 2 setbits. 3*2 = 6.

Your Task:
You do not need to read input or print anything. Your task is to complete the function bitMultiply() which takes the number N as input parameters and returns the product.


*/

#include <iostream>
using namespace std;
int bitMultiply(int N)
{
    // code here
    int i = 0;
    int temp = N;
    while (N)
    {
        N = N & (N - 1);
        i++;
    }
    return temp * i;
}
int main()
{
}