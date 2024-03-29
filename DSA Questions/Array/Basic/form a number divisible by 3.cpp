/*
Given an array arr of integers of length N, the task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3. If it is possible then print “1” and if not print “0”.

Example 1:

Input: N = 3
arr = {40, 50, 90}
Output: 1
Explaination: One such number is 405900.
Example 2:

Input: N = 2
arr = {1, 4}
Output: 0
Explaination: The numbers we can form 
are 14 and 41. But neither of them are 
divisible by 3.
Your Task:
You do not need to read input or print anything. Your task is to complete the function isPossible() which takes N and arr as input parameters and returns 1 if we can form a number by the digits of the given number, otherwise returns 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

#include <iostream>
using namespace std;
int isPossible(int N, int arr[])
{
    // code here
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = arr[i];
        while (temp)
        {
            total += temp % 10;
            temp = temp / 10;
        }
    }
    if (total % 3 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
}