/*
Given a non-negative integer n. Reverse the bits of n and print the number obtained after reversing the bits.
Note:  The actual binary representation of the number is being considered for reversing the bits, no leading 0’s are being considered.
 
Example 1:
Input : 
N = 11
Output:
13
Explanation:
(11)10 = (1011)2.
After reversing the bits we get:
(1101)2 = (13)10.
Example 2:

Input : 
N = 10
Output:
5
Explanation:
(10)10 = (1010)2.
After reversing the bits we get:
(0101)2 = (101)2
        = (5)10.
Your task:
You don't need to read input or print anything. Your task is to complete the function reverseBits() which takes an integer N as input and returns the number obtained after reversing bits.
 
Expected Time Complexity : O(number of bits in the binary representation of N)
Expected Auxiliary Space :  O(1)
 

*/

#include <iostream>
using namespace std;
unsigned int reverseBits(unsigned int n)
{
    //code here
    int temp = 0;
    while (n)
    {
        int k = n & 1;
        temp = temp | k;
        n = n >> 1;
        temp = temp << 1;
    }
    return temp >> 1;
}
int main()
{
}