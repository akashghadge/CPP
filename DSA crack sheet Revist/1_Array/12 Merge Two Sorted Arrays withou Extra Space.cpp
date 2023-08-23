/*
simple logic if first array last element is greater then pop that and add that to second array in trade of first element of array
*/
#include <bits/stdc++.h>
using namespace std;
void merge(long long a[], long long b[], int n, int m)
{
    int i = n - 1, j = 0;
    while (i >= 0 and j < m)
    {
        if (a[i] > b[j])
            swap(a[i--], b[j++]);
        else
            break;
    }
    sort(a, a + n);
    sort(b, b + m);
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    // Until i less than equal to k
    // or j is less than m
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
}
int main()
{
}