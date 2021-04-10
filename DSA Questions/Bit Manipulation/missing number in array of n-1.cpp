/*
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:

Input:
N = 10
A[] = {1,2,3,4,5,6,7,8,10}
Output: 9

Your Task :
You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


*/

#include <iostream>
using namespace std;
#include "vector"
int missingNum(vector<int> &array, int n)
{

    // Your code goes here
    // this solution may be interger overflow codition so we need to improve it
    // int sumA=(n*(n+1))/2;
    // int i=0;
    // int sum=0;
    // while(i<array.size()){
    //     sum+=array[i];
    //     i++;
    // }
    // return sumA-sum;

    // using bit manipulation is ideal solution
    // here x^x =0 so we xor all n elements and then do xor with existing array element and missing elementns only left out
    int i = 0;
    int j = 1;
    int sumO = 0;
    int sumAll = 0;
    while (i < array.size())
    {
        sumAll ^= j;
        sumO ^= array[i];
        j++;
        i++;
    }
    // loop will exist in n-1 element so we need to take care of last nth element
    sumAll ^= j;
    return sumO ^ sumAll;
}
int main()
{
}