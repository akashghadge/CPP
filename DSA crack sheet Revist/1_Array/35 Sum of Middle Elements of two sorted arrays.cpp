/*

*/
#include <bits/stdc++.h>
using namespace std;
int findMidSum(int a[], int b[], int n)
{
    // code here
    int i = 0, j = 0;
    int k = 0;
    int sum = 0;
    while (i < n and j < n)
    {
        if (a[i] <= b[j])
        {
            if (k == n - 1)
            {
                sum += a[i];
            }
            if (k == n)
            {
                sum += a[i];
            }
            i++;
        }
        else
        {
            if (k == n - 1)
            {
                sum += b[j];
            }
            if (k == n)
            {
                sum += b[j];
            }
            j++;
        }
        k++;
    }

    while (i < n)
    {
        if (k == n - 1)
        {
            sum += a[i];
        }
        if (k == n)
        {
            sum += a[i];
        }
        i++;
        k++;
    }
    while (j < n)
    {
        if (k == n - 1)
        {
            sum += b[j];
        }
        if (k == n)
        {
            sum += b[j];
        }
        j++;
        k++;
    }
    return sum;
}

int main()
{
}