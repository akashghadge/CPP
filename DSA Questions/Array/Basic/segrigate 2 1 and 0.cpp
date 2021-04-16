/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


*/

#include <iostream>
using namespace std;
void sort012(int a[], int n)
{
    int count1 = 0;
    int count2 = 0;
    int count0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
        if (a[i] == 1)
        {
            count1++;
        }
        if (a[i] == 2)
        {
            count2++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count0)
        {
            count0--;
            a[i] = 0;
        }
        else if (count1)
        {
            count1--;
            a[i] = 1;
        }
        else if (count2)
        {
            count2--;
            a[i] = 2;
        }
    }

    // this is dutch national flag solution
    // int lo = 0;
    // int hi = arr_size - 1;
    // int mid = 0;

    // // Iterate till all the elements
    // // are sorted
    // while (mid <= hi) {
    //     switch (a[mid]) {

    //     // If the element is 0
    //     case 0:
    //         swap(a[lo++], a[mid++]);
    //         break;

    //     // If the element is 1 .
    //     case 1:
    //         mid++;
    //         break;

    //     // If the element is 2
    //     case 2:
    //         swap(a[mid], a[hi--]);
    //         break;
    //     }
    // }
}
int main()
{
}