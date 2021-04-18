/*
Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on the right side(even position bits are highlighted in the binary representation of 23), and every odd position bit is swapped with an adjacent on the left side.

Example 1:

Input: N = 23
Output: 43
Explanation: 
Binary representation of the given number 
is 00010111 after swapping 
00101011 = 43 in decimal.
Example 2:

Input: N = 2
Output: 1
Explanation: 
Binary representation of the given number 
is 10 after swapping 01 = 1 in decimal.

Your Task: Your task is to complete the function swapBits() which takes an integer and returns an integer with all the odd and even bits swapped.


Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/

#include <iostream>
using namespace std;
unsigned int swapBits(unsigned int n)
{

    // Your code here
    // 	basically 0xaa gives one mask of all even bits on and 0x55... gives odd bits on
    int temp = n;
    temp = temp & 0xaaaaaaaa;
    n = n & 0x55555555;

    // shift all even bits to odd positon and odd to evne
    temp = temp >> 1;
    n = n << 1;
    return n | temp;
}
int main()
{
}