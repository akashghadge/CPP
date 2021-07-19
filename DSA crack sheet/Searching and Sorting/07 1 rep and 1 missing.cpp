/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
car a
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int *findTwoElement(int *arr, int n)
{
    // code here
    int *ans = new int(2);

    int xor1;

    int set_bit_no;

    int i;
    int x = 0;
    int y = 0;

    xor1 = arr[0];

    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two 
        sets by comparing a rightmost set
        bit of xor1 with the bit at the same 
        position in each element. Also, 
        get XORs of two sets. The two
        XORs are the output elements. 
        The following two for loops 
        serve the purpose */
    for (i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set*/
            y = y ^ arr[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set*/
            y = y ^ i;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            ans[0] = x;
            ans[1] = y;
            break;
        }
        else if (arr[i] == y)
        {
            ans[0] = y;
            ans[1] = x;
            break;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}