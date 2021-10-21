/*
Maximum product subset of an array
Difficulty Level : Easy
Last Updated : 18 Jun, 2021
Geek Week
Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be single element also.
Examples: 

Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int maxProductSubset(int arr[], int n)
{
    sort(arr, arr + n);
    int product = 1;
    bool flag1 = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            product *= arr[i];
            flag1 = true;
        }
    }
    int productTemp = product;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            productTemp *= arr[i];
            if (productTemp >= product)
            {
                product = productTemp;
                flag1 = true;
            }
        }
    }
    if (flag1)
    {
        return product;
    }
    return 0;
}

int maxProductSubsetOpt(int arr[], int n)
{
    int neg = 0;
    int zeros = 0;
    int max_neg = INT_MIN;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
            continue;
        }
        if (arr[i] < 0)
        {
            max_neg = max(arr[i], max_neg);
            neg++;
        }
        product *= arr[i];
    }
    if (zeros == n)
    {
        return 0;
    }
    if (neg & 1)
    {
        if (neg == 1 && zeros > 0 && neg + zeros == n)
        {
            return 0;
        }
        product /= max_neg;
    }
    return product;
}
int main()
{
    FAST;
    int a[] = {0, -1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubsetOpt(a, n);
    return 0;
}