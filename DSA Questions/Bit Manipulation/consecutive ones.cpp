/*
Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation: 
Binary representation of 14 is 
1110, in which 111 is the longest 
consecutive set bits of length is 3.
Example 2:

Input: N = 222
Output: 4
Explanation: 
Binary representation of 222 is 
11011110, in which 1111 is the 
longest consecutive set bits of length 4. 

Your Task: 
You don't need to read input or print anything. Your task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

*/

#include <iostream>
using namespace std;
int maxConsecutiveOnes(int N)
{
    // code here
    int c = 0;
    int maxC = 0;
    while (N)
    {
        if (N & 1)
        {
            c++;
        }
        else
        {
            c = 0;
        }
        if (c > maxC)
        {
            maxC = c;
        }
        N = N >> 1;
    }
    return maxC;
}
int main()
{
}