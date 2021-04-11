#include <iostream>
using namespace std;
// always add parenthesis for bit operations
/*
Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers.

Example 1: 

Input: M = 11, N = 9
Output: 2
Explanation: Binary representation of the given 
numbers are: 1011 and 1001, 
2nd bit from right is different.
Example 2:

Input: M = 52, N = 4
Output: 5
Explanation: Binary representation of the given 
numbers are: 110100â€¬ and 0100, 
5th-bit from right is different.
User Task:
The task is to complete the function posOfRightMostDiffBit() which takes two arguments m and n and returns the position of first different bits in m and n. If both m and n are the same then return -1 in this case.

Expected Time Complexity: O(max(log m, log n)).
Expected Auxiliary Space: O(1).


*/
int firstDiffBit(int a, int b)
{
    // here we compare each bit of number untill we get different bit
    // if there is no differnt bit then return -1;
    for (int i = 0; i < 31; i++)
    {
        // printf("%d %d\n", a & 1, b & 1);
        if (!(((a & 1) == 0 && (b & 1) == 0) || (a & 1 == 1 && b & 1 == 1)))
        {
            // cout << (a & 1) << (b & 1) << endl;

            return i + 1;
        }
        a = a >> 1;
        b = b >> 1;
    }
    return -1;
}

int firstDiffBitXor(int a, int b)
{
    int XOR = a ^ b;
    int m = 0;
    while (XOR)
    {
        if (XOR & 1)
        {
            return m + 1;
        }
        XOR = XOR >> 1;
        m++;
    }
    return -1;
}
int main()
{
    cout << firstDiffBit(10, 6) << endl;
    cout << firstDiffBitXor(10, 6) << endl;
}