/*
Given an N bit binary number, find the 1's complement of the number. The ones' complement of a binary number is defined as the value obtained by inverting all the bits in the binary representation of the number (swapping 0s for 1s and vice versa).
 

Example 1:

Input:
N = 3
S = 101
Output:
010
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1
Example 2:

Input:
N = 2
S = 10
Output:
01
Explanation:
We get the output by converting 1's in S
to 0 and 0s to 1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function onesComplement() which takes the binary string S, its size N as input parameters and returns 1's complement of S of size N.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

*/

#include <iostream>
using namespace std;
string onesComplement(string S, int N)
{
    //code here
    int i = 0;
    string temp = "";
    while (i < N)
    {
        if (S[i] == '1')
        {
            temp.push_back('0');
        }
        else
        {
            temp.push_back('1');
        }
        i++;
    }
    return temp;
}
int main()
{
}