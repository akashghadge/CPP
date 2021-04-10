/*
Given two integers a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator.

Example 1:

Input:
a = 10, b= 3
Output: 3
Exaplanation:
10/3 gives quotient as 3 
and remainder as 1.
Example 2:

Input:
a = 43, b = -8
Output: -5
Explanation:
43/-8 gives quotient as -5 and 
remainder as 3.
Your task:
You don't have to read input or print anything. Your task is to complete the function divide() which takes two integers a and b as input and returns the quotient after dividing a by b.
 
Expected Time Complexity: O(log(a))
Expected Auxiliary Space: O(1)

*/

#include <stdlib.h>
#include <iostream>
using namespace std;
long long divide(long long dividend, long long divisor)
{
    //code here
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    int temp = 0;
    int que = 0;
    for (int i = 31; i >= 0; --i)
    {
        if (temp + ((divisor) << i) <= dividend)
        {
            temp += divisor << i;
            que |= 1LL << i;
        }
    }
    return que * sign;
}
int main()
{
}