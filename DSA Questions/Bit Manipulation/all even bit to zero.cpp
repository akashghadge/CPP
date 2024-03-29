/*
Given a number N, change all bits at even positions to 0.

Example 1:

Input: N = 30
Output: 10 
Explanation: Binary representation of 
11110. Bits at Even positions are 
highlighted. After making all of them 
0, we get 01010. Hence the answer is 10.
Example 2:

Input:  N = 10
Output: 10
Explanation: Binary representation of 
1010. Bits at Even positions are 
highlighted. After making all of them 
0, we get 1010. Hence the answer is 10.

Your Task:  
You dont need to read input or print anything. Complete the function convertEvenBitToZero() which takes n as input parameter and returns the value of N after changing bits at even positions.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
*/

#include <iostream>
using namespace std;
#include <stack>
stack<int> bitStack;
void PrintBit(int n)
{
    while (n)
    {
        bitStack.push((n & 1));
        n = n >> 1;
    }
    while (!bitStack.empty())
    {
        cout << bitStack.top() << " ";
        bitStack.pop();
    }
    cout << endl;
}
long long int convertEvenBitToZero(long long int n)
{
    // code here
    // here mask 0xa only gives mask of all all odd bits are on
    n = n & 0xaaaaaaaa;
    PrintBit(0xaa);
    return n;
}
int main()
{
    convertEvenBitToZero(5);
}