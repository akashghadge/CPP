/*
Given two integers a and b. Find the sum of two numbers without using arithmetic operators.

Example 1:

Input:
a = 5, b = 3
Output: 8
Explanation :
5 + 3 = 8
Example 2:

Input:
a = 10, b = 30
Output: 40
Explanation:
10 + 30 = 40

*/
#include <iostream>
using namespace std;
int sum(int a, int b)
{
    // using half adder login
    if (!b)
    {
        return a;
    }

    int s = a ^ b;
    int carry = (a & b) << 1;

    return sum(s, carry);
}
int main()
{
    cout<<"Sum is :"<<sum(5,3)<<endl;
    
}